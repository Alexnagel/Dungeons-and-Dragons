#pragma once

#include "RoomType.h"
#include "Dungeon.h"
#include "Floor.h"
#include "DungeonParser.h"

class DungeonGenerator
{
private:
	// Constant variables
	const int NUMBER_OF_TYPES = 4;
	const int NUMBER_OF_FLOORS = 10;

	// Variables
	DungeonParser *dungeonParser;
	bool ContainsStartPosition, ContainsBossRoom, ContainsStaircaseUp, ContainsStaircaseDown;

	// Functions
	bool CheckRoom(RoomType type);
	Floor CreateFloor();

public:
	DungeonGenerator();
	~DungeonGenerator();

	Dungeon CreateDungeon();
};

