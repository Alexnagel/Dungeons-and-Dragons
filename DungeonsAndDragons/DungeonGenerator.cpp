#include "stdafx.h"
#include "DungeonGenerator.h"
#include "DungeonParser.h"
#include "GameManager.h"
#include "RoomType.h"
#include "Floor.h"
#include "Dungeon.h"
#include <random>
#include <vector>

using namespace std;

DungeonGenerator::DungeonGenerator()
{
	dungeonParser = new DungeonParser();

	ContainsStartPosition = true;
	ContainsBossRoom = true;
}

DungeonGenerator::~DungeonGenerator()
{
	delete(dungeonParser);
	dungeonParser = nullptr;
}

Dungeon DungeonGenerator::CreateDungeon()
{
	// Create all the floors
	vector<Floor> floorCollection;
	for (int i = 0; i < NUMBER_OF_FLOORS; i++)
	{
		ContainsStaircaseDown = false;
		ContainsStaircaseUp = false;

		if (i == 0)
		{
			ContainsStartPosition = false;
			ContainsStaircaseUp = true;
		}
		else if (i == NUMBER_OF_FLOORS - 1)
		{
			ContainsBossRoom = false;
			ContainsStaircaseDown = true;
		}

		cout << "FLOOR " << i << endl;
		cout <<  endl;

		floorCollection.push_back(CreateFloor());

		cout << endl;
	}

	// Create the dungeon
	DungeonParser parser = *dungeonParser;
	return parser.ParseDungeon(floorCollection);
}

Floor DungeonGenerator::CreateFloor()
{
	uniform_int_distribution<int> roomTypeGenerator(0, NUMBER_OF_TYPES);

	

	// Create a random floor
	vector<vector<RoomType>> floor;
	for (int x = 0; x < 10; x++)
	{
		vector<RoomType> row;
		for (int y = 0; y < 10; y++)
		{
			RoomType type = (RoomType) roomTypeGenerator(GameManager::random);

			while (!CheckRoom(type))
				type = (RoomType)roomTypeGenerator(GameManager::random);

			row.push_back(type);
			cout << row[y];
		}
		cout << endl;
		floor.push_back(row);
	}

	// Parse the floor
	DungeonParser parser = *dungeonParser;
	return parser.ParseFloor(floor);
}

bool DungeonGenerator::CheckRoom(RoomType type)
{
	bool result = true;

	switch (type)
	{
	case START:
		if (!ContainsStartPosition)
			ContainsStartPosition = true;
		else
			result = false;
		break;
	case STAIRCASE_UP:
		if (!ContainsStaircaseUp)
			ContainsStaircaseUp = true;
		else
			result = false;
		break;
	case STAIRCASE_DOWN:
		if (!ContainsStaircaseDown)
			ContainsStaircaseDown = true;
		else
			result = false;
		break;
	case BOSS_ROOM:
		if (!ContainsBossRoom)
			ContainsBossRoom = true;
		else
			result = false;
		break;
	case NORMAL_ROOM:
		break;
	default:
		break;
	}

	return result;
}
