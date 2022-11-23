#include "includes.h"

Jump::Jump()
{
}

Jump::~Jump()
{
}

void Jump::update(float)
{
}

void Jump::jump()
{
    // create a jump actions.
    auto jump = JumpBy::create(0.5, Vec2(0, 0), 100, 1);

    auto callbackJump = CallFunc::create([]() {
        log("Jumped!");
        });

    auto jumping = Sequence::create(jump, callbackJump, nullptr);

    //character->runAction(jumping);
}
