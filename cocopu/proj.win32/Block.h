#pragma once
class Block : public cocos2d::Action
{
public:
	Block();
	~Block();

	void block(Character* character);

private:
	float m_time;
};