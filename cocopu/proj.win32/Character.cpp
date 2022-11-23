#include "includes.h"

Character::Character()
{
	m_rectX = 0.0f;
	m_collideWallRight = false;
	m_collideWallLeft = false;
	m_collideDirt = false;
	m_side_right = true;
	m_timeSideCollide = 0.0f;
	m_timeLastAnim = 0.0f;
}

Character::~Character()
{
}

void Character::initialisation(float x, float y) {
	setTexture("MegamanTileset.png");
	setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0.5f, 0.0f));
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
	//auto moveBy = MoveBy::create(1, movement);
	//runAction(moveBy);

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
	float distance = getDistance(entity);
	float nextDistance = getNextDistance(entity);

	if (entity.getType() == Entity::WALL_RIGHT && distance <= 27 && m_side_right) {
		swipSide();
		m_collideWallRight = true;
		m_timeSideCollide = timeGetTime();
	}
	else if (entity.getType() == Entity::WALL_LEFT && distance <= 50 && !m_side_right) {
		swipSide();
		m_collideWallLeft = true;
		m_timeSideCollide = timeGetTime();
	}

	if (entity.getType() == Entity::DIRT && distance <= 16.0f)
	{
		m_collideDirt = true;
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
	if (m_side_right) {
		m_side_right = false;
		setFlippedX(true);
		//stopAllActions();
	}
	else {
		m_side_right = true;
		setFlippedX(false);
		//stopAllActions();
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