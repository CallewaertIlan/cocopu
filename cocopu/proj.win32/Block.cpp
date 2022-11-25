#include "includes.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::block(Character* character)
{
	vector<Character*> listCharacter = getGame()->getListCharacter();
	vector<Character*> newListCharacter;
	remove_copy(listCharacter.begin(), listCharacter.end(), newListCharacter.begin(), 20);

	getGame()->setListCharacter(newListCharacter);

	character->setTexture("metal.png");
	character->setType(Entity::DIRT);
	getGame()->getListObject().push_back(character);
	character->unscheduleUpdate();

}