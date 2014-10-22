#pragma once

#include "Room.h"

class RoomNode
{
private:
	Room north;
	Room east;
	Room south;
	Room west;
	Room current;

public:
	RoomNode();
	~RoomNode();

	Room GoNorth();
	Room GoEast();
	Room GoSouth();
	Room GoWest();
};

