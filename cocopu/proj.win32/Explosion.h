#pragma once
class Explosion : public Sprite
{
public:
	Explosion();
	~Explosion();

	void update(float) override;
	void start();
	void stop();
	void initialisation(float x, float y);
	float getDistance(Entity* entity);
	void animation();

	void deleteCollideEntities();

	CREATE_FUNC(Explosion);

private:
	float m_time;
	float m_timeLastAnim;
	float m_rectX;
};