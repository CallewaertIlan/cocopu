#pragma once

class Game : public cocos2d::Scene
{
public:
	enum AccelerationType
	{
		PAUSE = 0,
		ONE,
		TWO,
	};

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
	void setCountAlive(int value);
	void setListObject(vector<Entity*> list);
	void setListCharacter(vector<Character*> list);

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

	void setActionX2(bool X2);

	bool getActionX2();

	void addCountExit(int value);
	void addCountDeath(int value);
	void addCountSpawn(int value);

	void addCountAlive(int value);

	void addTimeAcceleration(float value);

	float getTimeAcceleration() { return m_timeAcceleration; };

	void setAcceleration(int acceleration);
	float getAcceleration() { return m_acceleration; };
	int getCountExit() { return m_countExit; };
	int getCountDeath() { return m_countDeath; };
	int getCountSpawn() { return m_countSpawn; };
	int getMaxSpawn() { return m_maxSpawn; };
	int getCountAlive() { return m_countAlive; };

	Label& getTimer() { return m_timer; };

	void menuCloseCallback(Ref* pSender);

	void LoadRessources();
	
	void addCharacter(float x, float y);

	void update(float) override;


	// implement the "static create()" method manually
	CREATE_FUNC(Game);
protected:
	int m_countExit;
	int m_countDeath;
	int m_countSpawn;
	int m_countAlive;
	int m_maxSpawn;

	bool m_jump;
	bool m_glide;
	bool m_dig;
	bool m_mine;
	bool m_explosion;
	bool m_block;
	bool m_X2;

	vector<string> m_listMaps;
	vector<Entity*> m_listObject;
	vector<Character*> m_listCharacter;
	Layer m_gameLayer;
	Controler m_controls;
	Label m_testAction;

	HUD* m_hud;

	float m_acceleationRectX;
	float m_timeAcceleration;

	Label m_timer;
	Label m_death;
	Label m_alive;
	Label m_exit;
	Label m_maxspawn;
	Label m_spawn;

	float m_timeStart;
	float m_time;
	float m_timeLastUpdate;
	float m_timeMax;

	int m_acceleration;
};
