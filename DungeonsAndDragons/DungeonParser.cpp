#include "stdafx.h"
#include "DungeonParser.h"

// Globals
Room roomCollection[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];
bool visitedRooms[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];

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
	int startX = GetRandomNumber(0, GameManager::NUMBER_OF_ROOMS_X - 1);
	int startY = GetRandomNumber(0, GameManager::NUMBER_OF_ROOMS_Y - 1);

	// Create an array to see which positions are visited
	visitedRooms[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];
	for (int y = 0; y < GameManager::NUMBER_OF_ROOMS_Y; y++)
	{
		for (int x = 0; x < GameManager::NUMBER_OF_ROOMS_X; x++)
		{
			visitedRooms[x][y] = false;
		}
	}

	// Push the initial position to the stack
	Position* startPosition = new Position(startX, startY);
	stack.push(*startPosition);

	// Start the search
	DFS(*startPosition);
}

void DungeonParser::DFS(Position pos)
{
	if (!visitedRooms[pos.GetX()][pos.GetY()])
	{
		Position* neighbour = GetNeighbour(pos);

		//if (neighbour->GetX() >= 0 && neighbour->GetY() >= 0)
		if (neighbour != nullptr)
		{
			stack.push(*neighbour);
			DFS(*neighbour);
		}
		else
		{
			stack.pop();
			DFS(stack.top());
		}
	}
}

Position* DungeonParser::GetNeighbour(Position pos)
{
	std::vector<Position*> neighbours;

	// Set all the neighbours
	if (pos.GetX() + 1 < GameManager::NUMBER_OF_ROOMS_X)
	{
		if (!visitedRooms[pos.GetX() + 1][pos.GetY()])
			neighbours.push_back(new Position(pos.GetX() + 1, pos.GetY()));
	}

	if (pos.GetX() - 1 >= 0)
	{
		if (!visitedRooms[pos.GetX() - 1][pos.GetY()])
			neighbours.push_back(new Position(pos.GetX() - 1, pos.GetY()));
	}

	if (pos.GetY() + 1 < GameManager::NUMBER_OF_ROOMS_Y)
	{
		if (!visitedRooms[pos.GetX()][pos.GetY() + 1])
			neighbours.push_back(new Position(pos.GetX(), pos.GetY() + 1));
	}

	if (pos.GetY() - 1 >= 0)
	{
		if (!visitedRooms[pos.GetX()][pos.GetY() - 1])
			neighbours.push_back(new Position(pos.GetX(), pos.GetY() - 1));
	}

	// Choose a random neighbour
	if (neighbours.size() > 0)
	{
		int randomNumber = GetRandomNumber(0, neighbours.size() - 1);
		return neighbours[randomNumber];
	}
	else
		return nullptr;// new Position(-1, -1);
}

int DungeonParser::GetRandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}