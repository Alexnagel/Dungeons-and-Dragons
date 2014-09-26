#include "stdafx.h"
#include "DungeonParser.h"
#include "Floor.h";
#include "RoomType.h"
#include "Dungeon.h"
#include <vector>

using namespace std;

DungeonParser::DungeonParser()
{
}


DungeonParser::~DungeonParser()
{
}

Floor DungeonParser::ParseFloor(vector<vector<RoomType>> floor)
{
	return Floor();
}

Dungeon DungeonParser::ParseDungeon(vector<Floor> floorCollection)
{
	return Dungeon();
}