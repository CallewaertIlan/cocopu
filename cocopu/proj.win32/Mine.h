#pragma once
class Mine : public cocos2d::Sprite
{
public:
	Mine();
	~Mine();

	void initialisation(float x, float y);

	void start();

	void stop();

	void update(float) override;

	void animation();

	void deleteCollideEntities();

	float getDistance(Entity* entity);

	CREATE_FUNC(Mine);

private:
	float m_time;
	float m_timeLastAnim;
	float m_rectX;
	bool m_side_right;
};