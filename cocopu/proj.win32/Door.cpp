#include "includes.h"

Door::Door()
{
	m_timeLastSpawn = 0.0f;
}

Door::~Door()
{
}

void Door::initialisation(float x, float y, int type) {
	m_typeDoor = type;
	if (type == Door::ENTER)
		m_type = Entity::DOOR_ENTER;
	else if (type == Door::EXIT)
		m_type = Entity::DOOR_EXIT;
	setTexture("door_open.png");
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0.5, 1));
	m_hitbox.initialisation(getPosition().x - getContentSize().width / 2.0f, getPosition().y - getContentSize().height, 32.0f, 18.0f * 3.0f);

	scheduleUpdate();
}

void Door::update(float value) {
	float time = timeGetTime();
	if (m_typeDoor == Door::ENTER) {
		if (getGame()->getMaxSpawn() > getGame()->getCountSpawn() && m_timeLastSpawn + 2000.0f < timeGetTime()) {
			int count = getGame()->getCountSpawn();
			count++;
			getGame()->setCountSpawn(count);
			getGame()->addCountAlive(1);
			m_timeLastSpawn = timeGetTime();

			float x = getPosition().x;
			float y = getPosition().y;

			Character* character = Character::create();
			character->initialisation(getPosition().x, getPosition().y - 36.0f);
			getGame()->getListCharacter().push_back(character);
			getGame()->getLayer().addChild(character);
		}
	}
}