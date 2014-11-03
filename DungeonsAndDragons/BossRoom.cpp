#include "stdafx.h"
#include "BossRoom.h"


BossRoom::BossRoom(int level)
	:Room(level)
{
}

std::string BossRoom::RoomCharacter()
{
	return "B";
}

BossRoom::~BossRoom()
{
}
