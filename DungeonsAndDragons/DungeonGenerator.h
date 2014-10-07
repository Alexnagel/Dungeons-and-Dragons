#pragma once

#include "RoomType.h"
#include "Dungeon.h"
#include "Floor.h"
#include "DungeonParser.h"
#include <random>

class DungeonGenerator
{
private:
	// Constant variables
	const int NUMBER_OF_TYPES = 4;
	const int NUMBER_OF_FLOORS = 10;
	const int CHANCE_ROOM = 75;
	const int CHANCE_STAIRCASE_UP = 25;
	const int CHANCE_STAIRCASE_DOWN = 50;
	const int CHANCE_BOSS = 75;
	const int CHANCE_START = 100;

	// Variables
	DungeonParser *dungeonParser;
	bool ContainsStartPosition, ContainsBossRoom, ContainsStaircaseUp, ContainsStaircaseDown;
	int seed;
	std::mt19937 rng;

	// Functions
	bool CheckRoom(int chance);
	Floor CreateFloor();
	int GetRandomNumber();

public:
	// Constructors
	DungeonGenerator();
	virtual ~DungeonGenerator();

	// Functions
	Dungeon CreateDungeon();
};

