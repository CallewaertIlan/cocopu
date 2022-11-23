#include "includes.h"

Hitbox::Hitbox()
{
	m_x = 0;
	m_y = 0;
	m_height = 0;
	m_width = 0;
}

Hitbox::~Hitbox()
{
}

void Hitbox::initialisation(float x, float y, float width, float height)
{
	setX(x);
	setY(y);
	setHeight(height);
	setWidth(width);
}

void Hitbox::setX(float x)
{
	m_x = x;
}

void Hitbox::setY(float y)
{
	m_y = y;
}

void Hitbox::setHeight(float height)
{
	m_height = height;
}

void Hitbox::setWidth(float width)
{
	m_width = width;
}

bool Hitbox::intersect(Hitbox* hitbox)
{
	float maxLeft = max(hitbox->getX(), m_x);
	float minRight = min(hitbox->getX() + hitbox->getWidth(), m_x + m_width);
	float maxBottom = max(hitbox->getY(), m_y);;
	float minTop = min(hitbox->getY() + hitbox->getHeight(), m_y + m_height);

	return (maxLeft < minRight) && (maxBottom < minTop);
}

void Hitbox::addX(float x) {
	m_x += x;
}

void Hitbox::addY(float y) {
	m_y += y;
}

void Hitbox::addHeight(float height) {
	m_height += height;
}

void Hitbox::addWidth(float width) {
	m_width += width;
}