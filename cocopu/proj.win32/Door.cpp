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

void Door::initialisation(float x, float y, int type) {
	m_typeDoor = type;
	m_type = Entity::DOOR_OPEN;
	setTexture("door_open.png");
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0.5, 1));

	scheduleUpdate();
}

void Door::update(float value) {
	float time = timeGetTime();
	if (m_typeDoor == Door::ENTER) {
		if (m_maxSpawn > m_coutSpawn && m_timeLastSpawn + 1000.0f < timeGetTime()) {
			m_coutSpawn++;
			m_timeLastSpawn = timeGetTime();

			float x = getPosition().x;
			float y = getPosition().y;

			Character* character = new Character();
			//character->initialisation(getPosition().x, getPosition().y);
			character->initialisation(0, 40);
			//m_game->getListCharacter().push_back(character);
			addChild(character);
		}
	}
}