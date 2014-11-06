#include "stdafx.h"
#include "Dungeon.h"
#include "Floor.h"

Dungeon::Dungeon()
{}

Dungeon::Dungeon(std::vector<std::shared_ptr<Floor>> floorCollection)
{
	FloorCollection = floorCollection;
}


Dungeon::~Dungeon()
{
	FloorCollection.clear();
}

// Functions
std::shared_ptr<Floor> Dungeon::GetFloor(int level)
{
	return FloorCollection.at(level);
}

std::shared_ptr<Room> Dungeon::GetRoom(int level, int x, int y)
{
	return (FloorCollection.at(level))->GetRoom(x, y);
}

std::shared_ptr<Room> Dungeon::GetStartRoom()
{
	return (FloorCollection.at(0))->GetStartRoom();
}

std::shared_ptr<Room> Dungeon::GetStaircaseDown(int level)
{
	return (FloorCollection.at(level))->GetStaircaseDown();
}

std::shared_ptr<Room> Dungeon::GetStaircaseUp(int level)
{
	return (FloorCollection.at(level))->GetStaircaseUp();
}

