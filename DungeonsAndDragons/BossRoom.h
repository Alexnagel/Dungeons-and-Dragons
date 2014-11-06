#pragma once
#include "Room.h"
#include "Boss.h"

class BossRoom : public Room
{
private:
	Boss boss;

public:
	BossRoom(int level);
	virtual ~BossRoom();
	std::string RoomCharacter();
};

