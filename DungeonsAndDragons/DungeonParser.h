#pragma once

#include "Floor.h";
#include "RoomType.h"
#include "Dungeon.h"
#include <vector>

using namespace std;

class DungeonParser
{
public:
	// Constructors
	DungeonParser();
	~DungeonParser();

	// Functions
	Floor ParseFloor(vector<vector<RoomType>> floor, int level);
	Dungeon ParseDungeon(vector<Floor> floorCollection);
};

