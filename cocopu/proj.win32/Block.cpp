#include "includes.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::block(Character* character)
{
	getGame()->addCountDeath(1);
	getGame()->addCountAlive(-1);

	vector<Character*> listCharacter = getGame()->getListCharacter();
	vector<Character*> newListCharacter;
	//remove_copy(listCharacter.begin(), listCharacter.end(), newListCharacter.begin(), 20);

	for (int i = 0; i < listCharacter.size(); i++)
	{
		if (listCharacter[i] != character) {
			newListCharacter.push_back(listCharacter[i]);
		}
	}

	getGame()->setListCharacter(newListCharacter);

	character->setTexture("Metal.jpg");
	getGame()->getListObject().push_back(character);
	getGame()->getListObject()[getGame()->getListObject().size() - 1]->setType(Entity::DIRT);
	getGame()->getListObject()[getGame()->getListObject().size() - 1]->setHitbox(
		getGame()->getListObject()[getGame()->getListObject().size() - 1]->getPosition().x,
		getGame()->getListObject()[getGame()->getListObject().size() - 1]->getPosition().y,
		32.0f, 18.0f);
	character->unscheduleUpdate();

}