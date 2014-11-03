#include "stdafx.h"
#include "RoomGenerator.h"


RoomGenerator::RoomGenerator()
{
}


RoomGenerator::~RoomGenerator()
{
}

Room* RoomGenerator::CreateRoom(RoomType type, int level)
{
	switch (type)
	{
	case RoomType::NORMAL_ROOM: return new NormalRoom(level); break;
	case RoomType::BOSS_ROOM: return new BossRoom(level); break;
	case RoomType::STAIRCASE_DOWN: return new Staircase(level, StairCaseDirection::DOWN); break;
	case RoomType::STAIRCASE_UP: return new Staircase(level, StairCaseDirection::UP); break;
	case RoomType::START: NormalRoom* room = new NormalRoom(level);room->SetStart(); return room; break;
	}
	return nullptr;
}
