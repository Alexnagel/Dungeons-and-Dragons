#pragma once
#include <memory>
#include "Room.h"
#include "RoomType.h"
#include "NormalRoom.h"
#include "BossRoom.h"
#include "Staircase.h"
#include "StairCaseDirection.h"

class RoomGenerator
{
public:
	RoomGenerator();
	~RoomGenerator();

	static std::shared_ptr<Room> CreateRoom(RoomType type, int level);
};

