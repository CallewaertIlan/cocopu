#pragma once

class Door : public Entity
{
public:
	enum door
	{
		ENTER = 0,
		EXIT,
	};
	Door();
	~Door();

	void init(float x, float y, int type);

	void update(float value) override;

private:
	int m_typeDoor;
	int m_maxSpawn;
	int m_coutSpawn;
	float m_timeLastSpawn;
};

