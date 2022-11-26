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
    for (int i = 0; i < getGame()->getListCharacter().size(); i++)
    {
        if (isIn(getGame()->getListCharacter()[i]->getHitboxGlobal(), touch) && getGame()->getListCharacter()[i]->getOpacity() != 0.0f)
        {
            if (getGame()->getActionExplosion())
            {
                explosion(getGame()->getListCharacter()[i]->getPosition().x, getGame()->getListCharacter()[i]->getPosition().y);
                getGame()->getListCharacter()[i]->setOpacity(0);
            }
            if (getGame()->getActionJump())
                jump(getGame()->getListCharacter()[i]);
            if (getGame()->getActionBlock())
                block(getGame()->getListCharacter()[i]);
        }
    }

    return true;
}

void Controler::onTouchEnded(Touch* touch, Event* event)
{
  
}

bool Controler::isIn(Hitbox* hitbox, Touch* touch)
{
    if (touch->getLocation().x < hitbox->getX() + hitbox->getWidth() && touch->getLocation().x > hitbox->getX())
        if (touch->getLocation().x < hitbox->getX() + hitbox->getWidth() && touch->getLocation().x > hitbox->getX())
            return true;
    return false;
}

void Controler::explosion(float x, float y)
{
    Explosion* explo = Explosion::create();
    explo->initialisation(x, y);
    explo->start();
    getGame()->getLayer().addChild(explo);
}



void Controler::jump(Character* character)
{
    Jump* jump = new Jump();
    jump->jump(character);
}

void Controler::block(Character* character)
{
    Block* block = new Block();
    block->block(character);
}