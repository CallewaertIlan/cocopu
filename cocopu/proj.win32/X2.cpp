#include "includes.h"

X2::X2()
{
}

X2::~X2()
{
}

void X2::initialisation(float x, float y)
{
	m_rectX = 0.0f;
	setPosition(x, y);
}

void X2::start(Entity& entity)
{
}
void X2::stop()
{
	unscheduleUpdate();
}

void X2::update(float)
{
	m_time = timeGetTime();
}
