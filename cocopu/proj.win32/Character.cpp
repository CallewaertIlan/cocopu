#include "includes.h"

Character::Character()
{
	setTexture("lemming.png");
	setPosition(Vec2(WINSIZE_X / 2.0f, WINSIZE_Y / 2.0f));
	setAnchorPoint(Vec2(0.5, 0));

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
		if (getPosition().x >= WINSIZE_X - 100.0f) {
			m_side_right = false;
		}
		movement.x += 2;
	}
	else{
		if (getPosition().x <= 100.0f) {
			m_side_right = true;
		}
		movement.x -= 2;
	}

	movement.y -= 2;

	if (movement.y != 0) {
		movement.x = 0;
	}
	auto moveBy = MoveBy::create(1, movement);
	runAction(moveBy);
}

void Character::problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}