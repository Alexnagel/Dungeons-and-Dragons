#include "stdafx.h"
#include "DungeonGenerator.h"
#include <random>
#include <vector>

using namespace std;

DungeonGenerator::DungeonGenerator()
{
	CreateFloor();
}

DungeonGenerator::~DungeonGenerator()
{
}

void CreateFloor()
{
	uniform_int_distribution<int> roomType(0, 10);

	// Create a random floor
	vector<vector<int>> floor;
	for (int x = 0; x < 10; x++)
	{
		vector<int> row;
		for (int y = 0; y < 10; y++)
		{
			row[y] = roomType(random);
		}
		floor[x] = row;
	}
}
