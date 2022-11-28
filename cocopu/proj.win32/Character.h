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

	void popEntityInList(Entity& entity);

	bool getDig() { return m_dig; };
	bool getMine() { return m_mine; };

	void setMine(bool mine);
	void setDig(bool dig);

	void setGlide(bool glide);

	Hitbox* getHitboxGlobal() { return &m_hitboxGlobal; };
	Hitbox* getHitboxLeft() { return &m_hitboxLeft; };
	Hitbox* getHitboxRight() { return &m_hitboxRight;};
	Hitbox* getHitboxBottom() { return &m_hitboxBottom;};
	Hitbox* getHitboxTop() { return &m_hitboxTop;};

	void problemLoading(const char* filename);

	// implement the "static create()" method manually
	CREATE_FUNC(Character);
private:
	Hitbox m_hitboxGlobal;
	Hitbox m_hitboxLeft;
	Hitbox m_hitboxRight;
	Hitbox m_hitboxBottom;
	Hitbox m_hitboxTop;

	float m_speed;
	bool m_isFalling;

	bool m_glide;
	bool m_mine;
	bool m_dig;

	float m_timeSideCollide;
	float m_time;
	float m_timeLastAnim;
	float m_timeLastSwitch;
	float m_rectX;

	bool m_collideWallRight;
	bool m_collideWallLeft;
	bool m_collideDirt;
	bool m_side_right;
};
