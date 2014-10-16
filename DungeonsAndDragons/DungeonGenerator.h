#pragma once

#include "DungeonParser.h"
#include "GameManager.h"
#include "RoomType.h"
#include "Floor.h"
#include "Dungeon.h"
#include <random>
#include <vector>

class DungeonGenerator
{
private:
	// Variables
	DungeonParser *dungeonParser;
	bool ContainsStartPosition, ContainsBossRoom, ContainsStaircaseUp, ContainsStaircaseDown;
	int seed;
	std::mt19937 rng;
	int distanceSinceSpecial;

	// Functions
	bool CheckRoom(int chance);
	Floor CreateFloor();
	int GetRandomNumber();
	RoomType CreateSpecialRoom();
	bool ContainsAllSpecial();

public:
	// Constructors
	DungeonGenerator();
	virtual ~DungeonGenerator();

	// Functions
	Dungeon CreateDungeon();

	// Constant variables
	static const int NUMBER_OF_TYPES = 4;
	static const int NUMBER_OF_FLOORS = 10;
	static const int NUMBER_OF_ROOMS_X = 10;
	static const int NUMBER_OF_ROOMS_Y = 10;

	static const int CHANCE_ROOM = 85;
	static const int CHANCE_STAIRCASE_UP = 25;
	static const int CHANCE_STAIRCASE_DOWN = 50;
	static const int CHANCE_BOSS = 75;
	static const int CHANCE_START = 100;
	static const int SPECIAL_ROOM_DISTANCE = 10;
};

