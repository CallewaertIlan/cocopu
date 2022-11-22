#pragma once

class Entity : public cocos2d::Node
{
public:
	enum type
	{
		DIRT = 0,
		WALL_RIGHT,
		WALL_LEFT,
		DOOR_OPEN,
		DOOR_CLOSED,

	};
	Entity();
	~Entity();

	int getType() { return m_type; };
	cocos2d::Sprite* getSprite() { return m_sprite; };

	void initialisation(float x, float y, int type);

private:
	cocos2d::Sprite* m_sprite;
	int m_type;
};
