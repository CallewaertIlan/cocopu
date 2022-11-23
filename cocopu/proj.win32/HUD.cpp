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
    createJumpButton(300, 37);
    createGlideButton(400, 37);
    createBlockButton(500, 37);
    createDigButton(600, 37);
    createExplosionButton(700, 37);
     
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
            std::cout << "Explosion button clicked" << std::endl;
            break;
        default:
            break;
        }
        });

    addChild(button);
}

void HUD::createText(float x, float y)
{

}