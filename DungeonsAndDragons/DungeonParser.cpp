#include "stdafx.h"
#include "DungeonParser.h"

DungeonParser::DungeonParser()
{
	seed = std::random_device()();
	rng = std::mt19937(seed);
}


DungeonParser::~DungeonParser()
{
}

Floor DungeonParser::ParseFloor(std::vector<std::vector<RoomType>> floor, int width, int height, int level)
{
	// Create all the rooms
	std::vector<std::vector<Room>> roomCollection;
	for (int y = 0; y < floor.size(); y++)
	{
		std::vector<Room> rowOfRooms;
		std::vector<RoomType> row = floor.at(y);
		for (int x = 0; x < row.size(); x++)
		{
			rowOfRooms.push_back(RoomGenerator::CreateRoom(row.at(x), level));
		}
	}

	// Connect all the rooms
	ConnectionAlgorithm(width, height);

	// Create and return the floor;
	return Floor();
}

Dungeon DungeonParser::ParseDungeon(std::vector<Floor> floorCollection)
{
	// TODO:
	// - Connect Floors to each other
	return Dungeon();
}

void DungeonParser::ConnectionAlgorithm(int width, int height)
{
	int north = 1;
	int east = 2;
	int south = 3;
	int west = 4;

	int startX = GetRandomNumber(0,1);
	int startX = GetRandomNumber(0, 1);
}

int DungeonParser::GetRandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}