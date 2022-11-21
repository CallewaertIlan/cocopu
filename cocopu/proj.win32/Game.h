#pragma once

class Game : public cocos2d::Scene
{
public:
	Game();
	~Game();

	Scene* createScene();
	virtual bool init();
	void menuCloseCallback(Ref* pSender);

	void LoadRessources();

	// implement the "static create()" method manually
	CREATE_FUNC(Game);

private:
	vector<Entity*> m_listEntities;
	Layer gameLayer;
};
