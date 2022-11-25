#pragma once

class Jump : public cocos2d::Action
{
public:
	Jump();
	~Jump();

	void update(float) override;
	void jump(Character* character);


private:
	float m_time;
};
