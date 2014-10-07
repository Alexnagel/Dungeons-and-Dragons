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
	
	seed = random_device()();
	rng = std::mt19937(seed);
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
	// Create a random floor
	vector<vector<RoomType>> floor;
	for (int x = 0; x < 10; x++)
	{
		vector<RoomType> row;
		for (int y = 0; y < 10; y++)
		{
			int chance = GetRandomNumber();
			RoomType type;

			if (chance <= CHANCE_ROOM)
			{
				type = RoomType::NORMAL_ROOM;
			}
			else
			{
				do
				{
					chance = GetRandomNumber();
				} while (!CheckRoom(chance));

				if (chance <= CHANCE_STAIRCASE_UP)
				{
					type = RoomType::STAIRCASE_UP;
				}
				else if (chance <= CHANCE_STAIRCASE_DOWN)
				{
					type = RoomType::STAIRCASE_DOWN;
				}
				else if (chance <= CHANCE_START)
				{
					type = RoomType::START;
				}
				else
				{
					type = RoomType::BOSS_ROOM;
				}
			}

			row.push_back(type);
			cout << row[y];
		}
		cout << endl;
		floor.push_back(row);
	}

	// Parse the floor
	DungeonParser parser = *dungeonParser;
	return parser.ParseFloor(floor, 0);
}

bool DungeonGenerator::CheckRoom(int chance)
{
	if (chance <= CHANCE_STAIRCASE_UP)
	{
		if (!ContainsStaircaseUp)
			return ContainsStaircaseUp = true;
	}
	else if (chance <= CHANCE_STAIRCASE_DOWN)
	{
		if (!ContainsStaircaseDown)
			return ContainsStaircaseDown = true;
	}
	else if (chance <= CHANCE_START)
	{
		if (!ContainsStartPosition)
			return ContainsStartPosition = true;
	}
	else
	{
		if (!ContainsBossRoom)
			return ContainsBossRoom = true;
	}

	return false;
}

int DungeonGenerator::GetRandomNumber()
{
	return uniform_int_distribution<int>(0, 100)(rng);
}