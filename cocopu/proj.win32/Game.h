#pragma once

class Game : public cocos2d::Scene
{
public:
	Game();
	~Game();

	virtual bool init();

	vector<Entity*>& getListObject() { return m_listObject; }
	vector<Character*>& getListCharacter() { return m_listCharacter;}
	Layer& getLayer() { return m_gameLayer;}
	Controler& getControls() { return m_controls;}

	void setCountExit(int value);
	void setCountDeath(int value);
	void setCountSpawn(int value);

	void addCountExit(int value);
	void addCountDeath(int value);
	void addCountSpawn(int value);

	int getCountExit() { return m_countExit; };
	int getCountDeath() { return m_countDeath; };
	int getCountSpawn() { return m_coutSpawn; };
	int getMaxSpawn() { return m_maxSpawn; };

	void menuCloseCallback(Ref* pSender);

	void LoadRessources();
	
	void addCharacter(float x, float y);

	void update(float) override;

	// implement the "static create()" method manually
	CREATE_FUNC(Game);

protected:
	int m_countExit;
	int m_countDeath;
	int m_coutSpawn;
	int m_maxSpawn;

	vector<Entity*> m_listObject;
	vector<Character*> m_listCharacter;
	Layer m_gameLayer;
	Controler m_controls;
};
