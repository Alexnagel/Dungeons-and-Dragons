#pragma once
#include "Room.h"
#include "RoomType.h"
#include "GameManager.h"

class Floor
{
private:
	std::vector<std::vector<Room*>> vRooms;
public:
	Floor();
	Floor(Room* rooms[][10]);

	void PrintFloor();

	virtual ~Floor();
};

