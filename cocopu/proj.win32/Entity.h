#pragma once

class Entity : public cocos2d::Sprite
{
public:
	enum type
	{
		DIRT = 0,
		WALL_RIGHT,
		WALL_LEFT,
		DOOR_OPEN,

	};
	Entity();
	~Entity();

	int getType() { return m_type; };
	//cocos2d::Sprite* getSprite() { return m_sprite; };

	void initialisation(float x, float y, int type);

	// implement the "static create()" method manually
	CREATE_FUNC(Entity);

protected:
	//cocos2d::Sprite* m_sprite;
	int m_type;
};
