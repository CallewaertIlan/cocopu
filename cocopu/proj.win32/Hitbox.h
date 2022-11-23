#pragma once

class Hitbox
{
public:
	Hitbox();
	~Hitbox();

	void setX(float x);
	void setY(float y);
	void setHeight(float height);
	void setWidth(float width);

	float getX() { return m_x; };
	float getY() { return m_y; };
	float getHeight() { return m_height; };
	float getWidth() { return m_width; };

	void initialisation(float x, float y, float width, float height);

	bool intersect(Hitbox* hitbox);

protected:
	float m_x;
	float m_y;
	float m_height;
	float m_width;
};
