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

Floor DungeonParser::ParseFloor(std::vector<std::vector<RoomType>> floor, int level)
{
	// Create all the rooms
	roomCollection[DungeonGenerator::NUMBER_OF_ROOMS_X][DungeonGenerator::NUMBER_OF_ROOMS_Y];
	for (int y = 0; y < floor.size(); y++)
	{
		std::vector<RoomType> row = floor.at(y);
		for (int x = 0; x < row.size(); x++)
		{
			roomCollection[x][y] = RoomGenerator::CreateRoom(row.at(x), level);
		}
	}

	// Connect all the rooms
	ConnectionAlgorithm();

	// Create and return the floor;
	// TODO: Create the floor.
	return Floor();
}

Dungeon DungeonParser::ParseDungeon(std::vector<Floor> floorCollection)
{
	// TODO:
	// - Connect Floors to each other
	return Dungeon();
}

// Using DFS algorithm to create a maze
void DungeonParser::ConnectionAlgorithm()
{
	// Create a random start position
	int startX = GetRandomNumber(0, DungeonGenerator::NUMBER_OF_ROOMS_X);
	int startY = GetRandomNumber(0, DungeonGenerator::NUMBER_OF_ROOMS_Y);

	// Create an array to see which positions are visited
	visitedRooms[DungeonGenerator::NUMBER_OF_ROOMS_X][DungeonGenerator::NUMBER_OF_ROOMS_Y];
	for (int y = 0; y < DungeonGenerator::NUMBER_OF_ROOMS_Y; y++)
	{
		for (int x = 0; x < DungeonGenerator::NUMBER_OF_ROOMS_X; x++)
		{
			visitedRooms[x][y] = false;
		}
	}

	// Start the search
	DFS(startX, startY);
}

void DungeonParser::DFS(int x, int y)
{

}

int DungeonParser::GetRandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}