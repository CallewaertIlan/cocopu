#pragma once

class Game : public cocos2d::Scene
{
public:
	Game();
	~Game();

	void LoadRessources();

private:
	vector<Entity*> m_listEntities;
};
