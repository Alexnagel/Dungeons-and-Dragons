#pragma once
#include "Room.h"

class BossRoom : public Room
{
	public:
		BossRoom(int level);
		virtual ~BossRoom();
		std::string RoomCharacter();
};

