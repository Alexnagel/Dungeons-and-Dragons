#pragma once
#include <memory>
#include "Room.h"

class Floor
{
private:
	std::vector<std::vector<Room*>> vFloor;
public:
	Floor();
	Floor(std::vector<std::vector<Room*>> floorVector);
	
	void PrintFloor();
	Room* GetRoom(int x, int y);
	Room* GetStartRoom();
	
	virtual ~Floor();
};

