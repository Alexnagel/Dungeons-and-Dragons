#pragma once

#include <random>
#include <vector>
#include <memory>

#include "GameManager.h"
#include "RoomType.h"
#include "Floor.h"
#include "Dungeon.h"
#include "DungeonParser.h"

class DungeonParser;
class DungeonGenerator
{
private:
	// Variables
	int seed;
	std::mt19937 rng;
	//std::unique_ptr<DungeonParser> dungeonParser;
	bool ContainsStartPosition, ContainsBossRoom, ContainsStaircaseUp, ContainsStaircaseDown;
	int distanceSinceSpecial;

	// Functions
	bool CheckRoom(int chance);
	std::shared_ptr<Floor> CreateFloor();
	int GetRandomNumber();
	RoomType CreateSpecialRoom();
	bool ContainsAllSpecial();

public:
	// Constructors
	DungeonGenerator();
	virtual ~DungeonGenerator();

	// Functions
	std::unique_ptr<Dungeon> CreateDungeon();

	// Constant variables
	static const int NUMBER_OF_TYPES = 4;
	static const int NUMBER_OF_FLOORS = 10;

	static const int CHANCE_ROOM = 85;
	static const int CHANCE_STAIRCASE_UP = 25;
	static const int CHANCE_STAIRCASE_DOWN = 50;
	static const int CHANCE_BOSS = 75;
	static const int CHANCE_START = 100;
	static const int SPECIAL_ROOM_DISTANCE = 10;
};



