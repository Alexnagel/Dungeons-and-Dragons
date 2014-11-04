#pragma once
#include <memory>
#include "Room.h"

class Floor
{
private:
	std::vector<std::vector<Room*>> vFloor;
	Floor& operator=(const Floor& other);

public:
	Floor();
	Floor(std::vector<std::vector<Room*>> floorVector);
	
	std::string PrintFloor();
	Room* GetRoom(int x, int y);
	Room* GetStartRoom();
	
	virtual ~Floor();
};

