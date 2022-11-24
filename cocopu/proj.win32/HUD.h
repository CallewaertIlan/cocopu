#pragma once
class HUD : public Layer
{
public:
	HUD();
	~HUD();
	void initialisation();

	void actionManager();
	void update(float) override;
	void createJumpButton(float x, float y);
	void createBlockButton(float x, float y);
	void createExplosionButton(float x, float y);
	void createDigButton(float x, float y);
	void createGlideButton(float x, float y);
	CREATE_FUNC(HUD);
private:
	float m_time;
	int m_action;
	bool m_jump;
	bool m_glide;
	bool m_dig;
	bool m_explosion;
	bool m_block;
	Vec2 action;

};
