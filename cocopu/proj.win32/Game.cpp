#include "includes.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::LoadRessources()
{
    m_listEntities.clear();
    ifstream inFile;

    inFile.open("Level.txt", ios::in);

    if (!inFile) {
        cout << "Unable to open file";
        return;
    }
    int count = 0;
    string tp;
    while (getline(inFile, tp)) {
        for (int i = 0; i < tp.size(); i++)
        {
            if (tp[i] == '1') {
                Entity* dirt;
                dirt->initialisation(i * 32.0f, count * 18.0f, Entity::DIRT);
                m_listEntities.push_back(dirt);
            }
            else if (tp[i] == 'P') {
                Entity* door_open;
                door_open->initialisation(i * 32.0f, count * 18.0f, Entity::DOOR_OPEN);
                m_listEntities.push_back(door_open);
            }
        }
        count++;
    inFile.close();
    }
}