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
		setTexture("metal.png");
		break;
	case WALL_RIGHT:
		setTexture("metal.png");
		break;
	case WALL_LEFT:
		setTexture("metal.png");
		break;
	case DOOR_OPEN:
		setTexture("door_open.png");
		break;
	default:
		break;
	}
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0, 1));

	scheduleUpdate();
}
