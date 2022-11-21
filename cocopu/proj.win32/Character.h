#pragma once

class Character : public cocos2d::Sprite
{
public:
	Character();
	~Character();

	void init(float x, float y);

	//cocos2d::Sprite* getSprite() { return m_sprite; };

	void update(float) override;
	void problemLoading(const char* filename);
	void move();
private:
	//cocos2d::Sprite* m_sprite;

	bool m_side_right;
};
