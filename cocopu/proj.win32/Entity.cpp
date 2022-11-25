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
	case DOOR_ENTER:
		setTexture("door_open.png");
		break;
	case DOOR_EXIT:
		setTexture("door_open.png");
		break;
	default:
		break;
	}
	setPosition(Vec2(x, y));
	m_hitbox.initialisation(getPosition().x - getContentSize().width / 2.0f, getPosition().y - getContentSize().height , 32.0f, 18.0f);

	setAnchorPoint(Vec2(0, 1));

	scheduleUpdate();
}

void Entity::setType(int type)
{
	m_type = type;
}
