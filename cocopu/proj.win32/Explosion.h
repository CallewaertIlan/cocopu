#pragma once
class Explosion : public cocos2d::Action
{
public:
	Explosion();
	~Explosion();

	void update(float) override;
	void explosion();

private:
	float m_time;
};