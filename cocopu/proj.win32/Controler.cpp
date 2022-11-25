#include "includes.h"

Scene* Controler::createScene()
{
    auto scene = Scene::create();
    auto layer = Controler::create();
    scene->addChild(layer);

    return scene;
}

bool Controler::init()
{
    if (!Layer::init())
    {
        return false;
    }

    labelTouchInfo = Label::createWithSystemFont("", "Marker Felt", 30);

    labelTouchInfo->setPosition(Vec2(
        Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = CC_CALLBACK_2(Controler::onTouchBegan, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    addChild(labelTouchInfo);
    return true;
}

bool Controler::onTouchBegan(Touch* touch, Event* event)
{
    Explosion* explo = Explosion::create();
    explo->initialisation(touch->getLocation().x, touch->getLocation().y);
    explo->start();
    getGame()->getLayer().addChild(explo);

    
    return true;
}

void Controler::onTouchEnded(Touch* touch, Event* event)
{
  
}
