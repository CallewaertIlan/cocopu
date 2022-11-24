#pragma once

class Entity : public cocos2d::Sprite
{
public:
	enum type
	{
		DIRT = 0,
		DOOR_ENTER,
		DOOR_EXIT,

	};
	Entity();
	~Entity();

	Hitbox* getHitbox() { return &m_hitbox; };
	int getType() { return m_type; };

	void initialisation(float x, float y, int type);

	// implement the "static create()" method manually
	CREATE_FUNC(Entity);

protected:
	Hitbox m_hitbox;
	int m_type;
};
