#include "includes.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init()
{
    m_countExit = 0;
    m_countDeath = 0;
    m_coutSpawn = 0;
    m_maxSpawn = 10;

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


void Game::update(float f) {

    // Update collide
    for (int i = 0; i < m_listCharacter.size(); i++)
    {
        for (int j = 0; j < m_listObject.size(); j++)
        {
            m_listCharacter[i]->collision(*m_listObject[j]);
        }
    }

}

void Game::LoadRessources()
{
    ifstream inFile;

    inFile.open("../Resources/level/Map.txt", ios::in);
    int count = 0;
    string tp;
    while (getline(inFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == '1') {
                Entity* dirt = Entity::create();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::DIRT);
                m_gameLayer.addChild(dirt, 0);
                dirt->setAnchorPoint(Vec2(0.5, 1));
                m_listObject.push_back(dirt);
            }
            else if (tp[i] == '2') {
                Entity* dirt = Entity::create();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::WALL_LEFT);
                m_gameLayer.addChild(dirt, 0);
                dirt->setAnchorPoint(Vec2(0.5, 1));
                m_listObject.push_back(dirt);
            }
            else if (tp[i] == '3') {
                Entity* dirt = Entity::create();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::WALL_RIGHT);
                m_gameLayer.addChild(dirt, 0);
                dirt->setAnchorPoint(Vec2(0.5, 1));
                m_listObject.push_back(dirt);
            }
            else if (tp[i] == 'D') {
                Door* door_enter = Door::create();
                door_enter->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Door::ENTER);
                m_listObject.push_back(door_enter);
                m_gameLayer.addChild(door_enter, 0);
            }
            else if (tp[i] == 'E') {
                Door* door_exit = Door::create();
                door_exit->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Door::EXIT);
                m_listObject.push_back(door_exit);
                door_exit->scheduleUpdate();
                m_gameLayer.addChild(door_exit, 0);
            }
        }
        count++;
    }
    inFile.close();
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
    m_coutSpawn = value;
}

void Game::addCountExit(int value) {
    m_countExit += value;
}

void Game::addCountDeath(int value) {
    m_countDeath += value;
}

void Game::addCountSpawn(int value) {
    m_coutSpawn += value;
}

void Game::setListObject(vector<Entity*> list)
{
    m_listObject.clear();
    for (int i = 0; i < list.size(); i++)
    {
        m_listObject.push_back(list[i]);
    }
}