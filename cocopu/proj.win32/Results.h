#pragma once
class Results : public cocos2d::Scene
{
public:
	Results();
	~Results();

	Scene* createScene();
	virtual bool init();
	void menuCloseCallback(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Results);

	Scene* createScene();

private:
	vector<Entity*> m_listObject;
	vector<Character*> m_listCharacter;
	Layer gameLayer;
};
