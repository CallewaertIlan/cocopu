#include "includes.h"

Character::Character()
{
	m_rectX = 0.0f;
	m_collideWallRight = false;
	m_collideWallLeft = false;
	m_collideDirt = false;
	m_side_right = true;
	m_timeLastAnim = 0.0f;
	m_timeLastSwitch = 0.0f;
}

Character::~Character()
{
}

void Character::initialisation(float x, float y) {
	setTexture("MegamanTileset.png");
	setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0.5f, 0.0f));
	setScale(SCALE_CHARACTER);

	m_type = Entity::CHARACTER;

	//m_hitboxLeft.initialisation(x - getContentSize().width / 2.0f + 7.0f, y + 1.0f, 2.0f, getContentSize().height + 2.0f);
	//m_hitboxRight.initialisation(x + getContentSize().width / 2.0f - 7.0f, y + 1.0f, 2.0f, getContentSize().height + 2.0f);
	//m_hitboxBottom.initialisation(x - getContentSize().width / 2.0f, y - 1.0f, getContentSize().width, 2.0f);
	//m_hitboxTop.initialisation(x - getContentSize().width / 2.0f, y + getContentSize().height + 1.0f, getContentSize().width, 2.0f);

	m_hitboxGlobal.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y, getContentSize().width * SCALE_CHARACTER, getContentSize().height * SCALE_CHARACTER);
	m_hitboxLeft.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y + 1.0f, 2.0f, getContentSize().height * SCALE_CHARACTER + 2.0f);
	m_hitboxRight.initialisation(x + getContentSize().width * SCALE_CHARACTER / 2.0f, y + 1.0f, 2.0f, getContentSize().height * SCALE_CHARACTER + 2.0f);
	m_hitboxBottom.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y - 1.0f, getContentSize().width * SCALE_CHARACTER, 2.0f);
	m_hitboxTop.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y + getContentSize().height * SCALE_CHARACTER + 1.0f, getContentSize().width * SCALE_CHARACTER, 2.0f);

	scheduleUpdate(); 
}


void Character::update(float value) {
	m_time = timeGetTime();
	move();
}

void Character::move() {
	Vec2 movement;
	if (m_side_right) {
		movement.x += 1;
	}
	else{
		movement.x -= 1;
	}

	movement.y -= 2;


	if (m_collideWallRight && movement.x > 0.0f) {
		movement.x = 0.0f;
		m_collideWallRight = false;
	}
	else if (m_collideWallLeft && movement.x < 0.0f) {
		movement.x = 0.0f;
		m_collideWallLeft = false;
	}
	if (m_collideDirt) {
		movement.y = 0.0f;
		m_collideDirt = false;
	}
	if (movement.y != 0.0f) {
		movement.x = 0.0f;
	}

	m_hitboxGlobal.addX(movement.x);
	m_hitboxLeft.addX(movement.x);
	m_hitboxRight.addX(movement.x);
	m_hitboxBottom.addX(movement.x);
	m_hitboxTop.addX(movement.x);

	m_hitboxGlobal.addY(movement.y);
	m_hitboxLeft.addY(movement.y);
	m_hitboxRight.addY(movement.y);
	m_hitboxBottom.addY(movement.y);
	m_hitboxTop.addY(movement.y);

	setPosition(getPosition().x + movement.x, getPosition().y + movement.y);

	if (m_time > m_timeLastAnim + 100.0f && movement.y == 0.0f)
		animation();
}

void Character::problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void Character::collision(Entity& entity)
{
	if (entity.getType() == Entity::DOOR_EXIT && m_hitboxBottom.intersect(entity.getHitbox()))
	{
		unscheduleUpdate();
		setOpacity(0);

	}
	if (entity.getType() == Entity::DIRT)
	{
		if (m_hitboxBottom.intersect(entity.getHitbox()))
			m_collideDirt = true;
		if (m_hitboxLeft.intersect(entity.getHitbox()))
		{
			swipSide();
			m_collideWallLeft = true;
		}
		if (m_hitboxRight.intersect(entity.getHitbox()))
		{
			swipSide();
			m_collideWallRight = true;
		}
	}

}

float Character::getDistance(Entity& entity)
{
	return sqrt(pow(entity.getPosition().x - getPosition().x, 2) + pow(entity.getPosition().y - getPosition().y, 2));
}

float Character::getNextDistance(Entity& entity)
{
	float add;
	if (m_side_right)
		add = 3;
	else
		add = -3;
	float result = sqrt(pow(entity.getPosition().x + add - getPosition().x, 2) + pow(entity.getPosition().y - getPosition().y, 2));
	return result;
}

void Character::swipSide()
{
	if (m_side_right && m_time > m_timeLastSwitch + 500.0f) {
		m_side_right = false;
		m_timeLastSwitch = timeGetTime();
		setFlippedX(true);
	}
	else if (m_time > m_timeLastSwitch + 500.0f) {
		m_side_right = true;
		m_timeLastSwitch = timeGetTime();
		setFlippedX(false);
	}
}

void Character::animation()
{
	m_rectX += 40.0f;
	if (m_rectX > 80.0f) {
		m_rectX = 0.0f;
	}
	setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
	m_timeLastAnim = m_time;
}