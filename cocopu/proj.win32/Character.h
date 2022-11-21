#pragma once

class Character : public cocos2d::Sprite
{
public:
	Character();
	~Character();

	void init(float x, float y);

	//cocos2d::Sprite* getSprite() { return m_sprite; };

	void update(float) override;

	void move();
	
	void swipSide();

	void collision(Entity& entity);
	float getDistance(Entity& entity);

	void problemLoading(const char* filename);
private:
	//cocos2d::Sprite* m_sprite;

	bool m_collideWall;
	bool m_collideDirt;
	bool m_side_right;
};
