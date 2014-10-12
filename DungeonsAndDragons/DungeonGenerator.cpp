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
		distanceSinceSpecial = 0;

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
				distanceSinceSpecial++;
			}
			else
			{
				type = CreateSpecialRoom();
			}

			row.push_back(type);
			cout << row[y];
		}
		cout << endl;
		floor.push_back(row);
	}

	// Parse the floor
	return dungeonParser->ParseFloor(floor, 0);
}

RoomType DungeonGenerator::CreateSpecialRoom()
{
	int chance;

	do {
		chance = GetRandomNumber();
	} while (CheckRoom(chance) && !ContainsAllSpecial());

	RoomType type = RoomType::NORMAL_ROOM;

	// To make the placement of the special rooms more random
	if (chance % 2 == 0 && distanceSinceSpecial > SPECIAL_ROOM_DISTANCE)
	{
		if (chance <= CHANCE_STAIRCASE_UP && !ContainsStaircaseUp)
		{
			type = RoomType::STAIRCASE_UP;
			ContainsStaircaseUp = true;
			distanceSinceSpecial = 1;
		}
		else if (chance <= CHANCE_STAIRCASE_DOWN && !ContainsStaircaseDown)
		{
			type = RoomType::STAIRCASE_DOWN;
			ContainsStaircaseDown = true;
			distanceSinceSpecial = 1;
		}
		else if (chance <= CHANCE_START && !ContainsStartPosition)
		{
			type = RoomType::START;
			ContainsStartPosition = true;
			distanceSinceSpecial = 1;
		}
		else if (!ContainsBossRoom)
		{
			type = RoomType::BOSS_ROOM;
			ContainsBossRoom = true;
			distanceSinceSpecial = 1;
		}
	}
	return type;
}

bool DungeonGenerator::ContainsAllSpecial()
{
	return (ContainsBossRoom && ContainsStaircaseDown && ContainsStaircaseUp && ContainsStartPosition);
}

bool DungeonGenerator::CheckRoom(int chance)
{
	if (chance <= CHANCE_STAIRCASE_UP)
	{
		return ContainsStaircaseUp;
	}
	else if (chance <= CHANCE_STAIRCASE_DOWN)
	{
		return ContainsStaircaseDown;
	}
	else if (chance <= CHANCE_BOSS)
	{
		return ContainsBossRoom;
	}
	else if (chance <= CHANCE_START)
	{
		return ContainsStartPosition;
	}

	return true;
}

int DungeonGenerator::GetRandomNumber()
{
	return uniform_int_distribution<int>(0, 100)(rng);
}