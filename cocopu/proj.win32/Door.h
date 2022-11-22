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

private:
	int m_typeDoor;

};

