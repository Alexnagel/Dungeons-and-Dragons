#include "stdafx.h"
#include "RoomGenerator.h"


RoomGenerator::RoomGenerator()
{
}


RoomGenerator::~RoomGenerator()
{
}

std::shared_ptr<Room> RoomGenerator::CreateRoom(RoomType type, int level)
{
	switch (type)
	{
	case RoomType::NORMAL_ROOM: return std::make_shared<NormalRoom>(NormalRoom(level)); break;
	case RoomType::BOSS_ROOM: return std::make_shared<BossRoom>(BossRoom(level)); break;
	case RoomType::STAIRCASE_DOWN: return std::make_shared<Staircase>(Staircase(level, StairCaseDirection::DOWN)); break;
	case RoomType::STAIRCASE_UP: return std::make_shared<Staircase>(Staircase(level, StairCaseDirection::DOWN)); break;
	case RoomType::START: return std::make_shared<NormalRoom>(NormalRoom(level, true)); break;
	}
	return std::make_shared<Room>();
}
