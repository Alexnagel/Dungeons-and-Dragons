#include "stdafx.h"
#include "DungeonParser.h"
#include "Floor.h"

// Globals
Room* roomCollection[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];
bool visitedRooms[GameManager::NUMBER_OF_ROOMS_X][GameManager::NUMBER_OF_ROOMS_Y];

DungeonParser::DungeonParser()
{
	seed = std::random_device()();
	rng = std::mt19937(seed);
}

DungeonParser::~DungeonParser()
{
}

Floor* DungeonParser::ParseFloor(std::vector<std::vector<RoomType>> floor, int level)
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

	// print maze
	/*
	for (int y = 0; y < floor.size(); y++)
	{
		std::vector<RoomType> row = floor.at(y);
		std::string rowTopstring = "";
		std::string rowstring = "";
		for (int x = 0; x < row.size(); x++)
		{
			std::array<bool, 2>connections = roomCollection[x][y]->GetConnections();

			if (connections[0])
				rowTopstring.append("  |");
			else
				rowTopstring.append("   ");

			if (connections[1])
				rowstring.append("--");
			else
				rowstring.append("  ");

			rowstring.append(roomCollection[x][y]->RoomCharacter());
		}
		std::cout << rowTopstring << std::endl;
		std::cout << rowstring << std::endl;
	}*/

	// Convert floor array to Vector 
	std::vector<std::vector<std::shared_ptr<Room>>> floorVector;
	int rows = GameManager::NUMBER_OF_ROOMS_Y;
	int cols = GameManager::NUMBER_OF_ROOMS_X;
	for (int row = 0; row < rows; row++)
	{
		std::vector<std::shared_ptr<Room>> roomRow;
		for (int col = 0; col < cols; col++)
		{
			roomRow.push_back(roomCollection[col][row]);
		}
		floorVector.push_back(roomRow);
	}

	// Create and return the floor;
	return new Floor(floorVector);
}

Dungeon* DungeonParser::ParseDungeon(std::vector<Floor *> floorCollection)
{
	// TODO:
	// - Connect Floors to each other
	return new Dungeon(floorCollection);
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
	Position startPosition = Position(startX, startY);
	stack.push(startPosition);

	// Start the search
	DFS(startPosition);
}

void DungeonParser::DFS(Position pos)
{
	if (!visitedRooms[pos.GetX()][pos.GetY()] || !stack.empty())
	{
		Position neighbour = GetNeighbour(pos);
		visitedRooms[pos.GetX()][pos.GetY()] = true;

		Room* mainRoom = roomCollection[pos.GetX()][pos.GetY()];
		Room* connectRoom = roomCollection[neighbour.GetX()][neighbour.GetY()];
		int mainX = pos.GetX();
		int mainY = pos.GetY();
		int neighbourX = neighbour.GetX();
		int neighbourY = neighbour.GetY();

		// Set the neighbour if it has a valid position
		if (neighbour.GetX() >= 0 && neighbour.GetY() >= 0)
		{
			if (mainX > neighbourX)
			{
				mainRoom->roomLeft = connectRoom;
				connectRoom->roomRight = mainRoom;
			}
			if (mainX < neighbourX)
			{
				mainRoom->roomRight = connectRoom;
				connectRoom->roomLeft = mainRoom;
			}
			if (mainY > neighbourY)
			{
				mainRoom->roomTop = connectRoom;
				connectRoom->roomBottom = mainRoom;
			}
			if (mainY < neighbourY)
			{
				mainRoom->roomBottom = connectRoom;
				connectRoom->roomTop = mainRoom;
			}

			stack.push(neighbour);
			DungeonParser::DFS(neighbour);
		}
		else
		{
			stack.pop();
			if (!stack.empty())
				DFS(stack.top());
		}
	}
}

Position DungeonParser::GetNeighbour(Position pos)
{
	std::vector<Position> neighbours;

	// Set all the neighbours
	if (pos.GetX() + 1 < GameManager::NUMBER_OF_ROOMS_X)
	{
		if (!visitedRooms[pos.GetX() + 1][pos.GetY()])
			neighbours.push_back(Position(pos.GetX() + 1, pos.GetY()));
	}

	if (pos.GetX() - 1 >= 0)
	{
		if (!visitedRooms[pos.GetX() - 1][pos.GetY()])
			neighbours.push_back(Position(pos.GetX() - 1, pos.GetY()));
	}

	if (pos.GetY() + 1 < GameManager::NUMBER_OF_ROOMS_Y)
	{
		if (!visitedRooms[pos.GetX()][pos.GetY() + 1])
			neighbours.push_back(Position(pos.GetX(), pos.GetY() + 1));
	}

	if (pos.GetY() - 1 >= 0)
	{
		if (!visitedRooms[pos.GetX()][pos.GetY() - 1])
			neighbours.push_back(Position(pos.GetX(), pos.GetY() - 1));
	}

	// Choose a random neighbour
	if (neighbours.size() > 0)
	{
		int randomNumber = GetRandomNumber(0, neighbours.size() - 1);
		return neighbours[randomNumber];
	}
	else
		return Position(-1, -1);
}

int DungeonParser::GetRandomNumber(int min, int max)
{
	return std::uniform_int_distribution<int>(min, max)(rng);
}