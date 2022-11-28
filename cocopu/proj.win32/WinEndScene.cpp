#include "includes.h"

USING_NS_CC;
Game* g_pGame2;

Scene* WinEndScene::createScene()
{
    return WinEndScene::create();
}


// on "init" you need to initialize your instance
bool WinEndScene::init()
{
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
        CC_CALLBACK_1(WinEndScene::WinRestartCallback, this));

    if (replayItem == nullptr ||
        replayItem->getContentSize().width <= 0 ||
        replayItem->getContentSize().height <= 0)
    {
        true;
    }
    else
    {
        replayItem->setPosition(Vec2(800, 300));
    }

    this->addChild(replayItem, 1);

    //exit btn
    auto closeItem = MenuItemImage::create(
        "ExitNormal.png",
        "ExitSelected.png",
        CC_CALLBACK_1(WinEndScene::WinEndCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        true;
    }
    else
    {
        closeItem->setPosition(Vec2(800, 200));
    }

    this->addChild(closeItem, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    auto label = Label::createWithTTF("CONGRATULATION, YOU WIN", "fonts/Marker Felt.ttf", 75);
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

    //alive
    auto alive = Label::createWithTTF("number of alive : " + getGame()->getCountAlive(), "fonts/Marker Felt.ttf", 75);
    if (alive == nullptr)
    {
        true;
    }
    else
    {
        // position the label on the center of the screen
        alive->setPosition(Vec2(800, 500));

        // add the label as a child to this layer
        this->addChild(alive, 1);
    }

    //exit
    auto exit = Label::createWithTTF("number of those who exit : " + getGame()->getCountExit(), "fonts/Marker Felt.ttf", 75);
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
    auto death = Label::createWithTTF("nomber of death : " + getGame()->getCountDeath(), "fonts/Marker Felt.ttf", 75);
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
    // create menu, it's an autorelease object
    auto close = Menu::create(closeItem, NULL);
    close->setPosition(Vec2::ZERO);
    this->addChild(close, 10);
    auto play = Menu::create(replayItem, NULL);
    play->setPosition(Vec2::ZERO);
    this->addChild(play, 10);

    return true;
}

void WinEndScene::WinEndCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}

void WinEndScene::WinRestartCallback(cocos2d::Ref* pSender)
{
    Scene* restartgameScene = Game::create();
    g_pGame2 = (Game*)restartgameScene;

    Director::getInstance()->replaceScene(restartgameScene);

}