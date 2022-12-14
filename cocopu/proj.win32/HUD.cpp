#include "includes.h"

HUD::HUD()
{
}

HUD::~HUD()
{
}


void HUD::update(float)
{
}

void HUD::initialisation() 
{
    createJumpButton(225, 37);
    createGlideButton(300, 37);
    createBlockButton(375, 37);
    createDigButton(450, 37);
    createExplosionButton(525, 37);
    createMineButton(600, 37);
    createX2Button(675, 37);
}


void HUD::createJumpButton(float x, float y)
{
    auto button = ui::Button::create("JumpButton.png", "JumpButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);
    

    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(true);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(false);
            getGame()->setActionX2(false);
            std::cout << "Jump button clicked" << std::endl;
            break;
        default:
            break;
        }
        }); 
    addChild(button);
   
}
void HUD::createGlideButton(float x, float y)
{
    auto button = ui::Button::create("GlideButton.png", "GlideButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);


    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(true);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(false);
            getGame()->setActionX2(false);
            std::cout << "Glide button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}
void HUD::createBlockButton(float x, float y)
{
    auto button = ui::Button::create("BlockButton.png", "BlockButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);


    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(true);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(false);
            getGame()->setActionX2(false);
            std::cout << "Block button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}
void HUD::createDigButton(float x, float y)
{
    auto button = ui::Button::create("DigButton.png", "DigButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);


    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(true);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(false);
            getGame()->setActionX2(false);
            std::cout << "Dig button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}
void HUD::createExplosionButton(float x, float y)
{
    auto button = ui::Button::create("ExplosionButton.png", "ExplosionButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);


    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(true);
            getGame()->setActionMine(false);
            getGame()->setActionX2(false);
            std::cout << "Explosion button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}

void HUD::createMineButton(float x, float y)
{
    auto button = ui::Button::create("MineButton.png", "MineButtonSelected.png");
    button->setPosition(Vec2(x, y));
    button->setScale(0.35);


    button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(true);
            getGame()->setActionX2(false);
            std::cout << "Mine button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}

void HUD::createX2Button(float x, float y)
{
    m_x2button = ui::Button::create("X2Button.png", "X2ButtonSelected.png");
    m_x2button->setPosition(Vec2(x, y));
    m_x2button->setScale(0.35);


    m_x2button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            getGame()->setActionJump(false);
            getGame()->setActionGlide(false);
            getGame()->setActionBlock(false);
            getGame()->setActionDig(false);
            getGame()->setActionExplosion(false);
            getGame()->setActionMine(false);
            getGame()->setActionX2(true);
            std::cout << "Mine button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(m_x2button);
}

void HUD::createDrawTimer(float x, float y)
{
    //if (getGame()->getTimer() != nullptr)
    //{
    //    // position the label on the center of the screen
    //    getGame()->getTimer()->setPosition(Vec2(x, y));

    //    // add the label as a child to this layer
    //    getGame()->getLayer().addChild(getGame()->getTimer(), 1);
    //}
}

void HUD::buttonCallback()
{
    auto label = Label::createWithTTF("Cocopu Menu", "fonts/Marker Felt.ttf", 75);
    if (label == nullptr)
    {
        //problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(500, 500));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
}