#include "includes.h"

Character::Character()
{
	m_sprite = Sprite::create("lemming.png");
	m_sprite->setPosition(Vec2(WINSIZE_X / 2.0f, WINSIZE_Y / 2.0f));
	m_sprite->setAnchorPoint(Vec2(0.5, 0));

	m_side_right = true;
}

Character::~Character()
{
}

void Character::update(float value) {
	move();
}

void Character::move() {
	if (m_side_right) {
		if (m_sprite->getPosition().x >= WINSIZE_X - 50.0f) {
			m_side_right = false;
		}
	    auto moveBy = MoveBy::create(1, Vec2(2, 0));
	    m_sprite->runAction(moveBy); 
	}
	else{
		if (m_sprite->getPosition().x <= 50.0f) {
			m_side_right = true;
		}
	    auto moveBy = MoveBy::create(1, Vec2(-2, 0));
	    m_sprite->runAction(moveBy);
	}
}

void Character::problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}