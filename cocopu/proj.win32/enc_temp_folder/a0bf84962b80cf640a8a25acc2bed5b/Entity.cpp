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

	Sprite* m_sprite = Sprite::create();
	m_sprite->setTexture("test2.png");
	m_sprite->setPosition(0, 0);
	m_sprite->setOpacity(75);
	m_sprite->setAnchorPoint(Vec2(0, 0));
	//m_sprite->setPosition(getPosition().x - getContentSize().width / 2.0f, getPosition().y - getContentSize().height);
	addChild(m_sprite);
}
