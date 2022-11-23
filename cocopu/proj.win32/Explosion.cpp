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
	if (m_rectX > 420.0f) {
		stop();
		deleteCollideEntities();
	}
	setTextureRect(Rect(m_rectX, 0.0f, 60.0f, 60.0f));
	m_timeLastAnim = m_time;
}

void Explosion::deleteCollideEntities() {
	vector<Entity*> listCopyEntities;
	vector<Entity*> listEntities = getGame()->getListObject();

	for (int i = 0; i < listEntities.size(); i++)
	{
		if (listEntities[i]) {
			listCopyEntities.push_back(listEntities[i]);
		}
	}

}