#pragma once

class Entity : public cocos2d::Node
{
public:
	enum type
	{
		DIRT = 0,
		WALL,
		DOOR_OPEN,
		DOOR_CLOSED,

	};
	Entity();
	~Entity();

	void initialisation(float x, float y, int type);

	cocos2d::Sprite* getSprite() { return m_sprite; };
private:
	cocos2d::Sprite* m_sprite;
	int m_type;
};
