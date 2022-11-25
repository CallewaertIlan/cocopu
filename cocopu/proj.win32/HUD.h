#pragma once
class HUD : public Layer
{
public:
	HUD();
	~HUD();
	void initialisation();

	void update(float) override;
	void createJumpButton(float x, float y);
	void createBlockButton(float x, float y);
	void createExplosionButton(float x, float y);
	void createDigButton(float x, float y);
	void createGlideButton(float x, float y);
	void createText(float x, float y);
	void buttonCallback();
	CREATE_FUNC(HUD);
private:
	float m_time;

};
