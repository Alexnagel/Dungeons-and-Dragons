#include "stdafx.h"
#include "DungeonGenerator.h"
#include "GameManager.h"
#include "RoomType.h"
#include <random>
#include <vector>

using namespace std;

DungeonGenerator::DungeonGenerator()
{
}

DungeonGenerator::~DungeonGenerator()
{
}

void DungeonGenerator::CreateFloor()
{
	uniform_int_distribution<int> roomType(0, 4);

	// Create a random floor
	vector<vector<RoomType>> floor;
	for (int x = 0; x < 10; x++)
	{
		vector<RoomType> row;
		for (int y = 0; y < 10; y++)
		{
			row.push_back((RoomType) roomType(GameManager::random));
			cout << row[y];
		}
		cout << endl;
		floor.push_back(row);
	}
}
