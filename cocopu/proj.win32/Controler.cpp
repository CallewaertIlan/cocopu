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

    EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = CC_CALLBACK_2(Controler::onTouchBegan, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool Controler::onTouchBegan(Touch* touch, Event* event)
{
    if (getGame()->getActionX2() && getGame()->getCountExit() > 0)
        x2();

    for (int i = 0; i < getGame()->getListCharacter().size(); i++)
    {
        if (isIn(getGame()->getListCharacter()[i]->getHitboxGlobal(), touch) && getGame()->getListCharacter()[i]->getOpacity() != 0.0f)
        {
            // Explosion
            if (getGame()->getActionExplosion())
            {
                explosion(getGame()->getListCharacter()[i]->getPosition().x, getGame()->getListCharacter()[i]->getPosition().y);
                getGame()->getListCharacter()[i]->setOpacity(0);
                getGame()->getListCharacter()[i]->unscheduleUpdate();
            }

            // Jump
            if (getGame()->getActionJump())
                jump(getGame()->getListCharacter()[i]);
            
            // Block
            if (getGame()->getActionBlock())
                block(getGame()->getListCharacter()[i]);
            
            // Glide
            if (getGame()->getActionGlide())
                glide(getGame()->getListCharacter()[i]);

            // Mine
            if (getGame()->getActionMine())
                mine(getGame()->getListCharacter()[i]);

            // Dig
            if (getGame()->getActionDig())
                dig(getGame()->getListCharacter()[i]);
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
        if (touch->getLocation().y < hitbox->getY() + hitbox->getHeight() && touch->getLocation().y > hitbox->getY())
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

void Controler::glide(Character* character)
{
    character->setGlide(true);
}

void Controler::mine(Character* character)
{
    if (character->getMine() == false)
        character->setMine(true);
    else
        character->setMine(false);
}

void Controler::dig(Character* character)
{
    if (character->getDig() == false)
        character->setDig(true);
    else
        character->setDig(false);
}

void Controler::x2()
{
    if (getGame()->getAcceleration() == Game::AccelerationType::PAUSE)
        getGame()->setAcceleration(Game::AccelerationType::ONE);
    else if (getGame()->getAcceleration() == Game::AccelerationType::ONE)
        getGame()->setAcceleration(Game::AccelerationType::TWO);
    else if (getGame()->getAcceleration() == Game::AccelerationType::TWO)
        getGame()->setAcceleration(Game::AccelerationType::PAUSE);
}