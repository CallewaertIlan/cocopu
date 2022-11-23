#pragma once
class Block : public cocos2d::Action
{
public:
	Block();
	~Block();

	void update(float) override;
	void block();

private:
	float m_time;
};