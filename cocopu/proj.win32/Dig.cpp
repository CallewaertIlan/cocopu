#include "includes.h"

Dig::Dig()
{
}

Dig::~Dig()
{
}

void Dig::initialisation(float x, float y)
{
	m_rectX = 0.0f;
	setTexture("pioche.png");
	setTextureRect(Rect(m_rectX, 0.0f, 60.0f, 60.0f));
	setPosition(x, y);
}

void Dig::start()
{
	Vec2 movement;
	if (m_side_right) {
		movement.x += 0;
	}
	else {
		movement.x -= 0;
	}
	scheduleUpdate();
}

void Dig::stop()
{
	unscheduleUpdate();

}

void Dig::update(float)
{
	m_time = timeGetTime();
	if (m_time > m_timeLastAnim + 100.0f)
		animation();
}

void Dig::animation()
{
	m_rectX += 60.0f;
	if (m_rectX > 420.0f) {
		stop();
		deleteCollideEntities();
	}
	setTextureRect(Rect(m_rectX, 0.0f, 60.0f, 60.0f));
	m_timeLastAnim = m_time;
}

void Dig::deleteCollideEntities()
{
	vector<int> listNumberEntitiesDelete;
	vector<Entity*> listCopyEntities;
	vector<Entity*> listEntities = getGame()->getListObject();
	bool verif = true;

	for (int i = 0; i < listEntities.size(); i++)
	{
		if (getDistance(listEntities[i]) <= 60.0f) {
			listNumberEntitiesDelete.push_back(i);
			getGame()->getListObject()[i]->setOpacity(0);
		}
	}

	for (int i = 0; i < listEntities.size(); i++)
	{
		for (int j = 0; j < listNumberEntitiesDelete.size(); j++)
		{
			if (i == listNumberEntitiesDelete[j]) {
				verif = false;
			}
		}
		if (verif) {
			listCopyEntities.push_back(listEntities[i]);
		}
		else {
			verif = true;
		}
	}

	getGame()->setListObject(listCopyEntities);
}

float Dig::getDistance(Entity* entity)
{
	return sqrt(pow(entity->getPosition().x - getPosition().x, 2) + pow(entity->getPosition().y - getPosition().y, 2));

}
