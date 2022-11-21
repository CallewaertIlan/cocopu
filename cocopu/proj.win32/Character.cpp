#include "includes.h"

Character::Character()
{
	setTexture("lemming.png");
	setPosition(Vec2(WINSIZE_X / 2.0f, WINSIZE_Y / 2.0f));
	setAnchorPoint(Vec2(0.5, 0));

	m_collideWall = false;
	m_collideDirt = false;
	m_side_right = true;
}

Character::~Character()
{
}

void Character::init(float x, float y) {
	setPosition(Vec2(x, y));
	scheduleUpdate();
}


void Character::update(float value) {
	move();
}

void Character::move() {
	Vec2 movement;
	if (m_side_right) {
		movement.x += 2;
	}
	else{
		movement.x -= 2;
	}

	movement.y -= 2;


	if (m_collideWall) {
		movement.x = 0;
		m_collideWall = false;
	}
	if (m_collideDirt) {
		movement.y = 0;
		m_collideDirt = false;
	}
	if (movement.y != 0) {
		movement.x = 0;
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
	if (entity.getType() == Entity::WALL && distance <= 18.35f)
	{
		swipSide();
		m_collideWall = true;
	}
	else if (entity.getType() == Entity::DIRT && distance <= 18.35f)
	{
		m_collideDirt = true;
	}
}

float Character::getDistance(Entity& entity)
{
	return sqrt(pow(entity.getSprite()->getPosition().x - getPosition().x, 2) + pow(entity.getSprite()->getPosition().y - getPosition().y, 2));
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