#pragma once

#include "stdafx.h"
#include "DungeonGenerator.h"
#include "Floor.h";
#include "Room.h"
#include "RoomType.h"
#include "RoomGenerator.h"
#include "Dungeon.h"
#include <vector>
#include <random>
#include <stack>

class DungeonParser
{
private:
	// Variables
	int seed;
	std::mt19937 rng;
	std::stack<int> stack;
	Room roomCollection[DungeonGenerator::NUMBER_OF_ROOMS_X][DungeonGenerator::NUMBER_OF_ROOMS_Y];
	bool visitedRooms[DungeonGenerator::NUMBER_OF_ROOMS_X][DungeonGenerator::NUMBER_OF_ROOMS_Y];

	// Functions
	void ConnectionAlgorithm();
	void DFS(int x, int y);
	void Carve();
	int GetDirection();
	int GetRandomNumber(int width, int height);

public:
	// Constructors
	DungeonParser();
	~DungeonParser();

	// Functions
	Floor ParseFloor(std::vector<std::vector<RoomType>> floor, int level);
	Dungeon ParseDungeon(std::vector<Floor> floorCollection);
};

