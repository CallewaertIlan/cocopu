#include "includes.h"

Door::Door()
{
	m_timeLastSpawn = 0.0f;
	m_maxSpawn = 10;
	m_coutSpawn = 0;
}

Door::~Door()
{
}

void Door::init(float x, float y, int type) {
	m_typeDoor = type;

	m_type = Entity::DOOR_OPEN;
	m_sprite = Sprite::create("door_open.png");
	m_sprite->setPosition(Vec2(x, y));
	m_sprite->setAnchorPoint(Vec2(0.5, 1));

	scheduleUpdate();
}

void Door::update(float value) {
	int test = 0;
	if (m_typeDoor == Door::ENTER) {
		if (m_maxSpawn > m_coutSpawn && m_timeLastSpawn + 50000.0f > timeGetTime()) {
			m_coutSpawn++;
			m_timeLastSpawn = timeGetTime();
			Character* character = new Character();
			character->initialisation(m_sprite->getPosition().x, m_sprite->getPosition().y);
		}
	}
}