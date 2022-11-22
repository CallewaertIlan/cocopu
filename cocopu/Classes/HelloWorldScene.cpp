#include "cocos2d.h"

#include "../../proj.win32/includes.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    m_side_right = true;

    if ( !Scene::init() )
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
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        closeItem->setPosition(Vec2(800, 400));
    }

    auto playItem = MenuItemImage::create(
        "PlayNormal.png",
        "PlaySelected.png",
        CC_CALLBACK_1(HelloWorld::menuPlayCallback, this));

    if (playItem == nullptr ||
        playItem->getContentSize().width <= 0 ||
        playItem->getContentSize().height <= 0)
    {
        problemLoading("'PlayNormal.png' and 'PlaySelected.png'");
    }
    else
    {
        playItem->setPosition(Vec2(800, 550));
    }

    // create menu, it's an autorelease object
    auto close = Menu::create(closeItem, NULL);
    close->setPosition(Vec2::ZERO);
    this->addChild(close, 10);
    auto play = Menu::create(playItem, NULL);
    play->setPosition(Vec2::ZERO);
    this->addChild(play, 10);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Cocopu Menu", "fonts/Marker Felt.ttf", 75);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);

        auto rotateBy = RotateBy::create(1.0f, 40.0f);
        sprite->runAction(RepeatForever::create(rotateBy));
    }


    /*Controler* controls = Controler::create();
    addChild(controls);*/

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
}

void HelloWorld::menuPlayCallback(Ref* pSender) {
    // create a scene. it's an autorelease object
    auto game = new Game;
    auto gameScene = game->createScene();

    Director::getInstance()->replaceScene(gameScene);
    //Director::getInstance()->runWithScene(gameScene);
}