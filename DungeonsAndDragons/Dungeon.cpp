#include "stdafx.h"
#include "Dungeon.h"
#include "Floor.h"

Dungeon::Dungeon()
{}

Dungeon::Dungeon(std::vector<Floor*> floorCollection)
{
	FloorCollection = floorCollection;
}


Dungeon::~Dungeon()
{
}

// Functions
Floor* Dungeon::GetFloor(int level)
{
	return FloorCollection.at(level);
}

Room* Dungeon::GetRoom(int level, int x, int y)
{
	return (FloorCollection.at(level))->GetRoom(x, y);
}

Room* Dungeon::GetStartRoom()
{
	return (FloorCollection.at(0))->GetStartRoom();
}
