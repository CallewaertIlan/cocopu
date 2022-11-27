#pragma once
class X2 : public cocos2d::Sprite
{
public:
	X2();
	~X2();

	void initialisation(float x, float y);

	void start(Entity& entity);

	void stop();

	void update(float) override;

	CREATE_FUNC(X2);

private:
	float m_time;
	float m_timeLastAnim;
	float m_rectX;
	bool m_side_right;
};
