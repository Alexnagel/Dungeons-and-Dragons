#pragma once

#include "Floor.h"
#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	virtual ~Dungeon();

	// Functions
	Floor GetFloor(int level);
	Room GetRoom(int level, int x, int y);
};

