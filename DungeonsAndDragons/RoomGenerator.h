#pragma once

#include "Room.h"
#include "RoomType.h"

class RoomGenerator
{
public:
	RoomGenerator();
	~RoomGenerator();

	static Room CreateRoom(RoomType type, int level);
};

