#include "includes.h"

Character::Character()
{
	setTexture("lemming.png");
	setPosition(Vec2(WINSIZE_X / 2.0f, WINSIZE_Y / 2.0f));
	setAnchorPoint(Vec2(0.5, 0));

	m_collideWallRight = false;
	m_collideWallLeft = false;
	m_collideDirt = false;
	m_side_right = true;
	m_timeSideCollide = 0.0f;
}

Character::~Character()
{
}

void Character::init(float x, float y) {
	setPosition(Vec2(x, y));
	scheduleUpdate();
}


void Character::update(float value) {
	m_time = timeGetTime();
	move();
}

void Character::move() {
	Vec2 movement;
	if (m_side_right) {
		movement.x += 3;
	}
	else{
		movement.x -= 3;
	}

	movement.y -= 3;


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

	if (entity.getType() == Entity::WALL_RIGHT && distance <= 32.5 && m_side_right) {
		swipSide();
		m_collideWallRight = true;
		m_timeSideCollide = timeGetTime();
	}
	else if (entity.getType() == Entity::WALL_LEFT && distance <= 34.5 && !m_side_right) {
		swipSide();
		m_collideWallLeft = true;
		m_timeSideCollide = timeGetTime();
	}

	if (entity.getType() == Entity::DIRT && distance <= 16.5f)
	{
		m_collideDirt = true;
	}
}

float Character::getDistance(Entity& entity)
{
	return sqrt(pow(entity.getSprite()->getPosition().x - getPosition().x, 2) + pow(entity.getSprite()->getPosition().y - getPosition().y, 2));
}

float Character::getNextDistance(Entity& entity)
{
	float add;
	if (m_side_right)
		add = 3;
	else
		add = -3;
	float result = sqrt(pow(entity.getSprite()->getPosition().x + add - getPosition().x, 2) + pow(entity.getSprite()->getPosition().y - getPosition().y, 2));
	return result;
}

void Character::swipSide()
{
	if (m_side_right) {
		m_side_right = false;
		//stopAllActions();
	}
	else {
		m_side_right = true;
		//stopAllActions();
	}
}