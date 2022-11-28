#pragma once

#define WINSIZE_X												1600
#define WINSIZE_Y												900
#define SCALE_CHARACTER											0.9f
#define BASE_SPEED												1.0f

using namespace std;

#include<time.h>
#include <random>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;

#include "Global.h"
#include "Hitbox.h"
#include "Entity.h"
#include "Character.h"
#include "Block.h"
#include "Jump.h"
#include "X2.h"
#include "Mine.h"
#include "Dig.h"
#include "Explosion.h"
#include "Door.h"
#include "Controler.h"
#include "HUD.h"
#include "Game.h"
#include "EndScene.h"
#include "WinEndScene.h"
#include "HelloWorldScene.h"
#include "AppDelegate.h"