#pragma once

class Game : public cocos2d::Scene
{
public:
	Game();
	~Game();

	Scene* createScene();
	virtual bool init();

	vector<Entity*>& getListObject() { return m_listObject; }
	vector<Character*>& getListCharacter() { return m_listCharacter;}
	Layer& getLayer() { return gameLayer;}
	Controler& getControls() { return m_controls;}

	void menuCloseCallback(Ref* pSender);

	void LoadRessources();
	
	void addCharacter(float x, float y);

	void update(float) override;

	// implement the "static create()" method manually
	CREATE_FUNC(Game);

private:
	vector<Entity*> m_listObject;
	vector<Character*> m_listCharacter;
	Layer gameLayer;
	Controler m_controls;
};
