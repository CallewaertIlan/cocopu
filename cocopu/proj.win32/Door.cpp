#include "includes.h"

Door::Door()
{
}

Door::~Door()
{
}

void Door::initialisation(float x, float y, int type) {
	m_typeDoor = type;

	m_type = Entity::DOOR_OPEN;
	m_sprite = Sprite::create("door_open.png");
	m_sprite->setPosition(Vec2(x, y));
	m_sprite->setAnchorPoint(Vec2(0.5, 1));
}