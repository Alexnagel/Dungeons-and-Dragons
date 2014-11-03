#pragma once
#include "Room.h"
class Floor;

class Dungeon
{
public:
	Dungeon();
	Dungeon(std::vector<Floor*> floorCollection);
	std::vector<Floor*> FloorCollection;

	// Functions
	Floor* GetFloor(int level);
	Room GetRoom(int level, int x, int y);
	virtual ~Dungeon();
};

