#pragma once
class Mine : public cocos2d::Action
{
public:
	Mine();
	~Mine();

	void update(float) override;
	void mine();

private:
	float m_time;
};