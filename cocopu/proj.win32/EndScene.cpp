#include "includes.h"

USING_NS_CC;
Game* g_pGame1;


Scene* EndScene::createScene()
{
    return EndScene::create();
}

// on "init" you need to initialize your instance
bool EndScene::init()
{
    if (getGame()->getTimeMax() + getGame()->getTimeStart() + getGame()->getTimeAcceleration() < getGame()->getTime())
        m_type = LOSE;
    else if (getGame()->getCountExit() < 5 && getGame()->getCountDeath() + getGame()->getCountExit() == getGame()->getMaxSpawn())
        m_type = LOSE;
    else if (getGame()->getCountExit() > 5 && getGame()->getCountDeath() + getGame()->getCountExit() == getGame()->getMaxSpawn())
        m_type = WIN;

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

    //restart btn
    auto replayItem = MenuItemImage::create(
        "RestartButton.png",
        "RestartButtonSelected.png",
        CC_CALLBACK_1(EndScene::RestartCallback, this));

    if (replayItem == nullptr ||
        replayItem->getContentSize().width <= 0 ||
        replayItem->getContentSize().height <= 0)
    {
        true;
    }
    else
    {
        replayItem->setPosition(Vec2(800, 300));
        addChild(replayItem, 1);
        //auto play = Menu::create(replayItem, NULL);
        //play->setPosition(Vec2::ZERO);
        //addChild(play, 10);
    }


    //exit btn
    auto closeItem = MenuItemImage::create(
        "ExitNormal.png",
        "ExitSelected.png",
        CC_CALLBACK_1(EndScene::EndCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        true;
    }
    else
    {
        closeItem->setPosition(Vec2(800, 200));
        addChild(closeItem, 1);
        //auto close = Menu::create(closeItem);
        //close->setPosition(Vec2::ZERO);
        //addChild(close, 10);
    }
     //create menu, it's an autorelease object
    if (this != nullptr)
    {
        Menu* close = Menu::create(closeItem, NULL);
        close->setPosition(Vec2::ZERO);
        addChild(close, 10);
        Menu* play = Menu::create(replayItem, NULL);
        play->setPosition(Vec2::ZERO);
        addChild(play, 10);
    }
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    if (m_type == EndScene::WIN)
    {
        auto label = Label::createWithTTF("CONGRATULATIONS, YOU WIN !!!!!", "fonts/Marker Felt.ttf", 75);
        if (label == nullptr)
        {
            true;
        }
        else
        {
            // position the label on the center of the screen
            label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                origin.y + visibleSize.height - label->getContentSize().height));

            // add the label as a child to this layer
            this->addChild(label, 1);
        }
    }
    else if (m_type == EndScene::LOSE)
    {
        auto label = Label::createWithTTF("GAME OVER, YOU LOSE", "fonts/Marker Felt.ttf", 75);
        if (label == nullptr)
        {
            true;
        }
        else
        {
            // position the label on the center of the screen
            label->setPosition(Vec2(origin.x + visibleSize.width / 2,
                origin.y + visibleSize.height - label->getContentSize().height));

            // add the label as a child to this layer
            this->addChild(label, 1);
        }
    }

    //time left
    auto timer = Label::createWithTTF("time left : " + std::to_string((int)(getGame()->getTimeMax() / 1000.0f) + (int)((getGame()->getTimeStart() - getGame()->getTime() + getGame()->getTimeAcceleration()) / 1000.0f)), "fonts/Marker Felt.ttf", 75);
    if (timer == nullptr)
    {
        true;
    }
    else
    {
        // position the label on the center of the screen
        timer->setPosition(Vec2(800, 500));

        // add the label as a child to this layer
        this->addChild(timer, 1);
    }

    //exit
    auto exit = Label::createWithTTF("number of those who exit : " + to_string(getGame()->getCountExit()), "fonts/Marker Felt.ttf", 75);
    if (exit == nullptr)
    {
        true;
    }
    else
    {
        // position the label on the center of the screen
        exit->setPosition(Vec2(800, 600));

        // add the label as a child to this layer
        this->addChild(exit, 1);
    }

    //death
    auto death = Label::createWithTTF("nomber of death : " + to_string(getGame()->getCountDeath()), "fonts/Marker Felt.ttf", 75);
    if (death == nullptr)
    {
        true;
    }
    else
    {
        // position the label on the center of the screen
        death->setPosition(Vec2(800, 700));

        // add the label as a child to this layer
        this->addChild(death, 1);
    }

    // add "EndScene" splash screen"
    auto sprite = Sprite::create("EndScene.png");
    if (sprite == nullptr)
    {
        true;
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);

        auto rotateBy = RotateBy::create(1.0f, 40.0f);
        sprite->runAction(RepeatForever::create(rotateBy));
    }

    return true;
}

void EndScene::EndCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}

void EndScene::RestartCallback(cocos2d::Ref* pSender)
{
    Scene* restartgameScene = Game::create();
    g_pGame1 = (Game*)restartgameScene;

    Director::getInstance()->replaceScene(restartgameScene);

}

void EndScene::initialisation(int value)
{
    m_type = value;
}