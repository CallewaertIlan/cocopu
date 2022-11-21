#include "includes.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::initialisation(float x, float y, int type)
{
	m_type = type;

	switch (m_type)
	{
	case DIRT:
		m_sprite = Sprite::create("metal.png");
		break;
	case WALL:
		m_sprite = Sprite::create("metal.png");
		break;
	case DOOR_OPEN:
		m_sprite = Sprite::create("door_open.png");
		break;
	default:
		break;
	}
	m_sprite->setPosition(Vec2(x, y));
	m_sprite->setAnchorPoint(Vec2(0, 1));

}
