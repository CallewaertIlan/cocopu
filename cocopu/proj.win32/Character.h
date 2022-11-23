#pragma once

class Character : public Entity
{
public:
	Character();
	~Character();

	void initialisation(float x, float y);

	void update(float) override;

	void move();
	void animation();
	
	void swipSide();

	void collision(Entity& entity);
	float getDistance(Entity& entity);
	float getNextDistance(Entity& entity);

	void problemLoading(const char* filename);

	// implement the "static create()" method manually
	CREATE_FUNC(Character);
private:
	float m_timeSideCollide;
	float m_time;
	float m_timeLastAnim;
	float m_rectX;

	bool m_collideWallRight;
	bool m_collideWallLeft;
	bool m_collideDirt;
	bool m_side_right;
};
