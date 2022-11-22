#include "includes.h"

Scene* Game::createScene()
{
    return Game::create();
}

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init()
{
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

    addChild(&gameLayer);

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
                Entity* dirt = new Entity();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::DIRT);
                dirt->setAnchorPoint(Vec2(0.5f, 0.5f));
                m_listObject.push_back(dirt);
                gameLayer.addChild(m_listObject[m_listObject.size() - 1]->getSprite(), 0);
            }
            else if (tp[i] == '2') {
                Entity* dirt = new Entity();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::WALL_LEFT);
                dirt->setAnchorPoint(Vec2(0.5f, 0.5f));
                m_listObject.push_back(dirt);
                gameLayer.addChild(m_listObject[m_listObject.size() - 1]->getSprite(), 0);
            }
            else if (tp[i] == '3') {
                Entity* dirt = new Entity();
                dirt->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::WALL_RIGHT);
                dirt->setAnchorPoint(Vec2(0.5f, 0.5f));
                m_listObject.push_back(dirt);
                gameLayer.addChild(m_listObject[m_listObject.size() - 1]->getSprite(), 0);
            }
            else if (tp[i] == 'D') {
                Entity* door_open = new Entity();
                door_open->initialisation(i * 32.0f, WINSIZE_Y - (count * 18.0f), Entity::DOOR_OPEN);
                door_open->setAnchorPoint(Vec2(0.5f, 0.5f));
                m_listObject.push_back(door_open);
                gameLayer.addChild(m_listObject[m_listObject.size() - 1]->getSprite(), 0);
            }
            else if (tp[i] == 'C') {
                Character* character = new Character();
                character->init(i * 32.0f, WINSIZE_Y - (count * 18.0f));
                m_listCharacter.push_back(character);
                gameLayer.addChild(character);
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
