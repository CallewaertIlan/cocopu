#pragma once

class Game : public cocos2d::Scene
{
public:
	Game();
	~Game();

	virtual bool init();

	vector<Entity*>& getListObject() { return m_listObject; }
	vector<Character*>& getListCharacter() { return m_listCharacter; }
	Layer& getLayer() { return m_gameLayer;}
	Controler& getControls() { return m_controls;}

	void setCountExit(int value);
	void setCountDeath(int value);
	void setCountSpawn(int value);
	void setListObject(vector<Entity*> list);

	void setActionJump(bool jump);

	bool getActionJump();

	void setActionBlock(bool block);

	bool getActionBlock();

	void setActionExplosion(bool explosion);

	bool getActionExplosion();

	void setActionDig(bool dig);

	bool getActionDig();

	void setActionMine(bool mine);

	bool getActionMine();

	void setActionGlide(bool glide);

	bool getActionGlide();

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

	Label& getTimer() { return m_timer; };

	// implement the "static create()" method manually
	CREATE_FUNC(Game);

protected:
	int m_countExit;
	int m_countDeath;
	int m_coutSpawn;
	int m_maxSpawn;

	bool m_jump;
	bool m_glide;
	bool m_dig;
	bool m_mine;
	bool m_explosion;
	bool m_block;

	vector<Entity*> m_listObject;
	vector<Character*> m_listCharacter;
	Layer m_gameLayer;
	Controler m_controls;

	Label m_timer;

	float m_timeStart;
	float m_timeMax;
};
