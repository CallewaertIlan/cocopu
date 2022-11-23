#pragma once
class Dig : public cocos2d::Action
{
public:
	Dig();
	~Dig();

	void update(float) override;
	void dig();

private:
	float m_time;
};