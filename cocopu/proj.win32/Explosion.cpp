#include "includes.h"

Explosion::Explosion()
{
}

Explosion::~Explosion()
{
}

void Explosion::initialisation(float x, float y)
{
	m_rectX = 0.0f;
	setTexture("explosion.png");
	setTextureRect(Rect(m_rectX, 0.0f, 60.0f, 60.0f));
	setPosition(x, y);
}

void Explosion::start()
{
	scheduleUpdate();
}

void Explosion::stop()
{
	unscheduleUpdate();
}

void Explosion::update(float)
{
	m_time = timeGetTime();
	if (m_time > m_timeLastAnim + 100.0f)
		animation();
}

void Explosion::animation()
{
	m_rectX += 60.0f;
	if (m_rectX > 420.0f)
		stop();
	else if (m_rectX > 0.0f)
		deleteCollideEntities();
	setTextureRect(Rect(m_rectX, 0.0f, 60.0f, 60.0f));
	m_timeLastAnim = m_time;
}

void Explosion::deleteCollideEntities() {
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

float Explosion::getDistance(Entity* entity) {
	return sqrt(pow(entity->getPosition().x - getPosition().x, 2) + pow(entity->getPosition().y - getPosition().y, 2));
}