#include "includes.h"

Character::Character()
{
	m_speed = BASE_SPEED;
	m_isFalling = false;
	m_rectX = 0.0f;
	m_collideWallRight = false;
	m_collideWallLeft = false;
	m_collideDirt = false;
	m_side_right = true;
	m_timeLastAnim = 0.0f;
	m_timeLastSwitch = 0.0f;
	m_glide = false;
	m_dig = false;
	m_mine = false;
}

Character::~Character()
{
}

void Character::initialisation(float x, float y) {
	setTexture("MegamanTileset.png");
	setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
	setPosition(Vec2(x, y));
	setAnchorPoint(Vec2(0.5f, 0.0f));
	setScale(SCALE_CHARACTER);

	m_type = Entity::CHARACTER;

	//m_hitboxLeft.initialisation(x - getContentSize().width / 2.0f + 7.0f, y + 1.0f, 2.0f, getContentSize().height + 2.0f);
	//m_hitboxRight.initialisation(x + getContentSize().width / 2.0f - 7.0f, y + 1.0f, 2.0f, getContentSize().height + 2.0f);
	//m_hitboxBottom.initialisation(x - getContentSize().width / 2.0f, y - 1.0f, getContentSize().width, 2.0f);
	//m_hitboxTop.initialisation(x - getContentSize().width / 2.0f, y + getContentSize().height + 1.0f, getContentSize().width, 2.0f);

	m_hitboxGlobal.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y, getContentSize().width * SCALE_CHARACTER, getContentSize().height * SCALE_CHARACTER);
	m_hitboxLeft.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y + 1.0f, 2.0f, getContentSize().height * SCALE_CHARACTER + 2.0f);
	m_hitboxRight.initialisation(x + getContentSize().width * SCALE_CHARACTER / 2.0f, y + 1.0f, 2.0f, getContentSize().height * SCALE_CHARACTER + 2.0f);
	m_hitboxBottom.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y - 1.0f, getContentSize().width * SCALE_CHARACTER, 2.0f);
	m_hitboxTop.initialisation(x - getContentSize().width * SCALE_CHARACTER / 2.0f, y + getContentSize().height * SCALE_CHARACTER + 1.0f, getContentSize().width * SCALE_CHARACTER, 2.0f);

	scheduleUpdate(); 
}


void Character::update(float value) {
	m_time = timeGetTime();
	move();
	if (getPosition().y < 0)
	{
		getGame()->addCountDeath(1);
		getGame()->addCountAlive(-1);
		unscheduleUpdate();
		setOpacity(0);
	}
}

void Character::move() {
	Vec2 movement;
	if (m_side_right) {
		//movement.x += (1.0f * m_speed);
		movement.x += 1.0f;
	}
	else{
		//movement.x -= (1.0f * m_speed);
		movement.x -= 1.0f;
	}

	//movement.y -= (2.0f * m_speed);
	movement.y -= 2.0f;


	if (m_collideWallRight && movement.x >= 0.0f) {
		movement.x = 0.0f;
		m_collideWallRight = false;
	}
	else if (m_collideWallLeft && movement.x <= 0.0f) {
		movement.x = 0.0f;
		m_collideWallLeft = false;
	}
	if (m_collideDirt) {
		movement.y = 0.0f;
		m_collideDirt = false;
	}
	if (movement.y != 0.0f) {
		movement.x = 0.0f;
	}

	if (movement.y == 0.0f) {
		m_isFalling = false;
		m_speed = BASE_SPEED;
	}
	else {
		m_speed = m_speed * 1.03;
		m_isFalling = true;
	}

	if (m_isFalling && m_glide)
	{
		setTexture("glide.png");
		setTextureRect(Rect(m_rectX, 0.0f, 35.0f, 40.0f));
	}
	else {
		setTexture("MegamanTileset.png");
		setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
		m_glide = false;

	}

	m_hitboxGlobal.addX(movement.x);
	m_hitboxLeft.addX(movement.x);
	m_hitboxRight.addX(movement.x);
	m_hitboxBottom.addX(movement.x);
	m_hitboxTop.addX(movement.x);

	m_hitboxGlobal.addY(movement.y);
	m_hitboxLeft.addY(movement.y);
	m_hitboxRight.addY(movement.y);
	m_hitboxBottom.addY(movement.y);
	m_hitboxTop.addY(movement.y);

	setPosition(getPosition().x + movement.x, getPosition().y + movement.y);

	if (m_time > m_timeLastAnim + 100.0f)
		animation();
}

void Character::problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void Character::collision(Entity& entity)
{
	if (entity.getType() == Entity::DOOR_EXIT && m_hitboxBottom.intersect(entity.getHitbox()))
	{
		unscheduleUpdate();
		setOpacity(0);
		setPosition(0, 0);

		m_hitboxBottom.setX(0);
		m_hitboxBottom.setY(0);

		m_hitboxLeft.setX(0);
		m_hitboxLeft.setY(0);

		m_hitboxRight.setX(0);
		m_hitboxRight.setY(0);

		m_hitboxTop.setX(0);
		m_hitboxTop.setY(0);

		m_hitboxGlobal.setX(0);
		m_hitboxGlobal.setY(0);


		getGame()->addCountExit(1);

	}
	if (entity.getType() == Entity::DIRT)
	{
		if (m_hitboxBottom.intersect(entity.getHitbox()))
		{
			if (m_isFalling == true && m_speed > 2.07f)
				m_dig = false;
			if (m_dig)
			{
				popEntityInList(entity);
				m_speed = BASE_SPEED;
			}
			else
			{
				if (m_speed >= 10.0f && !m_glide) {
					// die
					m_speed = 1.0f;
					unscheduleUpdate();
					setOpacity(0);
					getGame()->addCountDeath(1);
					getGame()->addCountAlive(-1);
				}
				m_collideDirt = true;
			}
		}

		if (m_hitboxLeft.intersect(entity.getHitbox()))
		{
			if (m_mine)
			{
				popEntityInList(entity);
			}
			else
			{
				swipSide();
				m_collideWallLeft = true;
			}
		}
		else if (m_hitboxRight.intersect(entity.getHitbox()))
		{
			if (m_mine)
			{
				popEntityInList(entity);
			}
			else
			{
				swipSide();
				m_collideWallRight = true;
			}
		}
	}

}

float Character::getDistance(Entity& entity)
{
	return sqrt(pow(entity.getPosition().x - getPosition().x, 2) + pow(entity.getPosition().y - getPosition().y, 2));
}

float Character::getNextDistance(Entity& entity)
{
	float add;
	if (m_side_right)
		add = 3;
	else
		add = -3;
	float result = sqrt(pow(entity.getPosition().x + add - getPosition().x, 2) + pow(entity.getPosition().y - getPosition().y, 2));
	return result;
}

void Character::swipSide()
{
	if (m_side_right && m_time > m_timeLastSwitch + 500.0f) {
		m_side_right = false;
		m_timeLastSwitch = timeGetTime();
		setFlippedX(true);
	}
	else if (m_time > m_timeLastSwitch + 500.0f) {
		m_side_right = true;
		m_timeLastSwitch = timeGetTime();
		setFlippedX(false);
	}
}

void Character::animation()
{
	m_rectX += 40.0f;
	if (m_rectX > 80.0f) {
		m_rectX = 0.0f;
	}
	setTextureRect(Rect(m_rectX, 90.0f, 35.0f, 40.0f));
	m_timeLastAnim = m_time;
}

void Character::setGlide(bool glide)
{
	m_glide = glide;
}

void Character::setMine(bool mine)
{
	m_mine = mine;
}

void Character::setDig(bool dig)
{
	m_dig = dig;
}

void Character::popEntityInList(Entity& entity)
{
	vector<Entity*> newListEntities;
	vector<Entity*> listEntities = getGame()->getListObject();

	for (int i = 0; i < listEntities.size(); i++)
	{
		if (listEntities[i] != &entity) {
			newListEntities.push_back(listEntities[i]);
		}
		else {
			getGame()->getListObject()[i]->setOpacity(0);
		}
	}
	getGame()->setListObject(newListEntities);
}