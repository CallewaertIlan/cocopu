#include "cocos2d.h"

#include "../../proj.win32/includes.h"

USING_NS_CC;

Scene* EndScene::createScene()
{
    return EndScene::create();
}

// on "init" you need to initialize your instance
bool EndScene::init()
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
        closeItem->setPosition(Vec2(800, 400));
    }

    this->addChild(closeItem, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("GAME OVER", "fonts/Marker Felt.ttf", 75);
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

    return true;
}

void EndScene::EndCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}