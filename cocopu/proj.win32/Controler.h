#pragma once

#include "cocos2d.h"

class Controler : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    void explosion(float x, float y);
    void jump(Character* character);
    void block(Character* character);
    void glide(Character* character);

    void mine(Character* character);
    void dig(Character* character);

    bool isIn(Hitbox* hitbox, Touch* touch);

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    //virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    //virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

    CREATE_FUNC(Controler);

private:
    Touch* m_touch;
    cocos2d::Label* labelTouchInfo;
};