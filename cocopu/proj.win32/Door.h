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

	void initialisation(float x, float y, int type);
	int getDoorType() { return m_typeDoor; };

	void update(float value) override;

	// implement the "static create()" method manually
	CREATE_FUNC(Door);

private:
	int m_typeDoor;
	float m_timeLastSpawn;
};

