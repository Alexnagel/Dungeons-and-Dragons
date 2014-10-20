#pragma once

#include "stdafx.h"
#include "DungeonGenerator.h"
#include "Floor.h"
#include "Position.h"
#include "Room.h"
#include "RoomType.h"
#include "RoomGenerator.h"
#include "GameManager.h"
#include "Dungeon.h"
#include <vector>
#include <stack>

class DungeonParser
{
private:
	// Variables
	int seed;
	std::mt19937 rng;
	std::stack<Position> stack;
	//std::vector<std::vector<Room>> roomCollection;
	//std::vector<std::vector<bool>> visitedRooms;

	// Functions
	void ConnectionAlgorithm();
	void DFS(Position pos);
	void Carve();
	int GetDirection();
	Position GetNeighbour(Position pos);
	int GetRandomNumber(int width, int height);

public:
	// Constructors
	DungeonParser();
	~DungeonParser();

	// Functions
	Floor ParseFloor(std::vector<std::vector<RoomType>> floor, int level);
	Dungeon ParseDungeon(std::vector<Floor> floorCollection);
};
