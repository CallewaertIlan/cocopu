#include "includes.h"

Game::Game()
{
    m_countExit = 0;
    m_countDeath = 0;
    m_countSpawn = 0;
    m_maxSpawn = 0;

    m_timeStart = 0.0f;
    m_timeMax = 0.0f;

    m_jump = false;
    m_glide = false;
    m_block = false;
    m_dig = false;
    m_explosion = false;
    m_mine = false;
    m_X2 = false;
}

Game::~Game()
{
}

bool Game::init()
{
    srand(time(NULL));
    m_countExit = 0;
    m_countDeath = 0;
    m_countAlive = 0;
    m_countSpawn = 0;
    m_maxSpawn = 10;

    m_timeStart = timeGetTime();
    m_timeMax = 1000.0f * 1000.0f;

    m_jump = false;
    m_glide = false;
    m_block = false;
    m_dig = false;
    m_explosion = false;
    m_mine = false;
    m_X2 = false;

    m_listMaps.push_back("Map1.txt");
    m_listMaps.push_back("Map2.txt");
    m_listMaps.push_back("Map3.txt");
    m_listMaps.push_back("Map4.txt");

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("Game Cocopu", "fonts/Marker Felt.ttf", 24);
    if (label != nullptr)
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    if (&m_timer != nullptr)
    {
        // position the label on the center of the screen
        m_timer.setPosition(Vec2(780, 37));
        m_timer.setScale(2.0f);

        // add the label as a child to this layer
        getLayer().addChild(&m_timer, 1);
    }

    if (&m_testAction != nullptr)
    {
        // position the label on the center of the screen
        m_testAction.setPosition(Vec2(930, 37));
        m_testAction.setScale(2.0f);

        m_testAction.setString("None");

        // add the label as a child to this layer
        addChild(&m_testAction, 1);
    }

    if (&m_alive != nullptr)
    {
        // position the label on the center of the screen
        m_alive.setPosition(Vec2(1050, 37));
        m_alive.setScale(2.0f);
        // add the label as a child to this layer
        getLayer().addChild(&m_alive, 1);
    }

    if (&m_death != nullptr)
    {
        // position the label on the center of the screen
        m_death.setPosition(Vec2(1150, 37));
        m_death.setScale(2.0f);
        // add the label as a child to this layer
        getLayer().addChild(&m_death, 1);
    }

    if (&m_exit != nullptr)
    {
        // position the label on the center of the screen
        m_exit.setPosition(Vec2(1250, 37));
        m_exit.setScale(2.0f);
        // add the label as a child to this layer
        getLayer().addChild(&m_exit, 1);
    }

    if (&m_spawn != nullptr)
    {
        // position the label on the center of the screen
        m_spawn.setPosition(Vec2(1350, 37));
        m_spawn.setScale(2.0f);
        // add the label as a child to this layer
        getLayer().addChild(&m_spawn, 1);
    }

    if (&m_maxspawn != nullptr)
    {
        // position the label on the center of the screen
        m_maxspawn.setPosition(Vec2(1500, 37));
        m_maxspawn.setScale(2.0f);
        // add the label as a child to this layer
        getLayer().addChild(&m_maxspawn, 1);
    }

    HUD* hud = HUD::create();
    hud->initialisation();

    addChild(hud);

    addChild(&m_gameLayer);


    m_controls.init();
    addChild(&m_controls);

    LoadRessources();

    scheduleUpdate();

    return true;
}


void Game::update(float f)
{
    //death count
    string countDeath = std::to_string(m_countDeath);
    m_death.setString("death :" + countDeath);

    //spawn count
    string countSpawn = std::to_string(m_countSpawn);
    m_spawn.setString("spawn : " + countSpawn);

    //exit count
    string countExit = std::to_string(m_countExit);
    m_exit.setString("exit : " +countExit);

    //maxcount
    string countMaxSpawn = std::to_string(m_maxSpawn);
    m_maxspawn.setString("maxspawn :" +countMaxSpawn);

    //alive count
    string countAlive = std::to_string(m_countAlive);
    m_alive.setString("alive :" + countAlive);

    // Update time
    if (m_timeMax + m_timeStart < timeGetTime())
    {
        // create a scene. it's an autorelease object
        auto time_up = new EndScene;
        auto endScene = time_up->createScene();
        Director::getInstance()->replaceScene(endScene);
    }

    int time = (int)timeGetTime();
    string timeNow = std::to_string(((int)m_timeMax + ((int)m_timeStart - (int)time)) / 1000);
    m_timer.setString("time: " + timeNow);

    if (m_jump) {
        m_testAction.setString("Jump");
    }
    else if (m_glide) {
        m_testAction.setString("Glide");
    }
    else if (m_dig) {
        m_testAction.setString("Dig");
    }
    else if (m_mine) {
        m_testAction.setString("Mine");
    }
    else if (m_explosion) {
        m_testAction.setString("Explosion");
    }
    else if (m_block) {
        m_testAction.setString("Block");
    }
    else if (m_X2) {
        m_testAction.setString("X2");
    }

    // Update collide
    for (int i = 0; i < m_listCharacter.size(); i++)
    {
        for (int j = 0; j < m_listObject.size(); j++)
        {
            m_listCharacter[i]->collision(*m_listObject[j]);
        }
    }

    //end 
    if (getCountExit() < 5 && getCountDeath() + getCountExit() == getMaxSpawn())
    {
        auto end = new EndScene;
        auto endScene = end->createScene();
        Director::getInstance()->replaceScene(endScene);
    }
    else if (getCountExit() >= 5 && getCountDeath() + getCountExit() == getMaxSpawn())
    {
        auto WinEnd = new WinEndScene;
        auto WinEndScene = WinEnd->createScene();
        Director::getInstance()->replaceScene(WinEndScene);
    }
}

void Game::LoadRessources()
{
    m_listObject.clear();

    ifstream inFile;
    int random = rand() % m_listMaps.size();
    bool verfiListEmpty = true;
    for (int i = 0; i < m_listMaps.size(); i++)
    {
        if (m_listMaps[i] != "") {
            verfiListEmpty = false;
        }
    }
    if (!verfiListEmpty) {
        while (m_listMaps[random] == "")
        {
            random = rand() % m_listMaps.size();
        }
        inFile.open("../Resources/level/" + m_listMaps[random], ios::in);
        m_listMaps[random] = "";

        if (!inFile) {
            cout << "Unable to open file";
            return;
        }

        //test map
        //inFile.open("../Resources/level/Map.txt", ios::in);
        //inFile.open("../Resources/level/MAP_COCOPU.txt", ios::in);

        int count = 0;
        string tp;
        while (getline(inFile, tp)) {
            for (int i = 0; i < tp.size(); i++)
            {
                if (tp[i] == '1') {
                    Entity* dirt = Entity::create();
                    dirt->initialisation(i * 32.0f + 32.0f / 2.0f, WINSIZE_Y - (count * 18.0f), Entity::DIRT);
                    m_gameLayer.addChild(dirt, 0);
                    dirt->setAnchorPoint(Vec2(0.5, 1));
                    m_listObject.push_back(dirt);
                }
                else if (tp[i] == 'D') {
                    Door* door_enter = Door::create();
                    door_enter->initialisation(i * 32.0f + 32.0f / 2.0f, WINSIZE_Y - (count * 18.0f), Door::ENTER);
                    m_listObject.push_back(door_enter);
                    m_gameLayer.addChild(door_enter, 0);
                }
                else if (tp[i] == 'E') {
                    Door* door_exit = Door::create();
                    door_exit->initialisation(i * 32.0f + 32.0f / 2.0f, WINSIZE_Y - (count * 18.0f), Door::EXIT);
                    m_listObject.push_back(door_exit);
                    door_exit->scheduleUpdate();
                    m_gameLayer.addChild(door_exit, 0);
                }
            }
            count++;
        }
        inFile.close();
    }
}

void Game::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

}

void Game::addCharacter(float x, float y)
{
    Character* character = new Character();
    character->initialisation(0, 0);
    m_listCharacter.push_back(character);
    m_gameLayer.addChild(character);
}

void Game::setCountExit(int value) {
    m_countExit = value;
}

void Game::setCountDeath(int value) {
    m_countDeath = value;
}

void Game::setCountSpawn(int value) {
    m_countSpawn = value;
}

void Game::setCountAlive(int value) {
    m_countAlive = value;
}

void Game::addCountExit(int value) {
    m_countExit += value;
}

void Game::addCountDeath(int value) {
    m_countDeath += value;
}

void Game::addCountSpawn(int value) {
    m_countSpawn += value;
}

void Game::addCountAlive(int value) {
    m_countAlive += value;
}

void Game::setListObject(vector<Entity*> list)
{
    m_listObject.clear();
    for (int i = 0; i < list.size(); i++)
    {
        m_listObject.push_back(list[i]);
    }
}

void Game::setListCharacter(vector<Character*> list)
{
    m_listCharacter.clear();
    for (int i = 0; i < list.size(); i++)
    {
        m_listCharacter.push_back(list[i]);
    }
}

//jump
void Game::setActionJump(bool jump)
{
    m_jump = jump;

}

bool Game::getActionJump()
{
    return m_jump;
}

//block
void Game::setActionBlock(bool block)
{
    m_block = block;
}

bool Game::getActionBlock()
{
    return m_block;

}

//explosion
void Game::setActionExplosion(bool explosion)
{
    m_explosion = explosion;

}

bool Game::getActionExplosion()
{
    return m_explosion;
}

//dig
void Game::setActionDig(bool dig)
{
    m_dig = dig;

}

bool Game::getActionDig()
{
    return m_dig;

}

//mine
void Game::setActionMine(bool mine)
{
    m_mine = mine;

}

bool Game::getActionMine()
{
    return m_mine;

}

//glide
void Game::setActionGlide(bool glide)
{
    m_glide = glide;

}

bool Game::getActionGlide()
{
    return m_glide;

}

//X2
void Game::setActionX2(bool X2)
{
    m_X2 = X2;

}

bool Game::getActionX2()
{
    return m_X2;

}