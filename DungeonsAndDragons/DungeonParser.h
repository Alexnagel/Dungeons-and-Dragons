#pragma once

#include "stdafx.h"
#include "DungeonParser.h"
#include "Floor.h";
#include "Room.h"
#include "RoomType.h"
#include "RoomGenerator.h"
#include "Dungeon.h"
#include <vector>
#include <random>

class DungeonParser
{
private:
	// Variables
	int seed;
	std::mt19937 rng;

	// Functions
	void ConnectionAlgorithm(int width, int height);
	void Carve();
	int GetDirection();
	int GetRandomNumber(int min, int max);

public:
	// Constructors
	DungeonParser();
	~DungeonParser();

	// Functions
	Floor ParseFloor(std::vector<std::vector<RoomType>> floor, int width, int height, int level);
	Dungeon ParseDungeon(std::vector<Floor> floorCollection);
};

