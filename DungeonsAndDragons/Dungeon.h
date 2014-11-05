#pragma once
#include <memory>
#include "Room.h"
class Floor;

class Dungeon
{
public:
	Dungeon();
	Dungeon(std::vector<std::shared_ptr<Floor>> floorCollection);
	std::vector<std::shared_ptr<Floor>> FloorCollection;

	// Functions
	std::shared_ptr<Floor> GetFloor(int level);
	std::shared_ptr<Room> GetRoom(int level, int x, int y);
	std::shared_ptr<Room> GetStartRoom();
	std::shared_ptr<Room> GetStaircaseDown(int level);
	std::shared_ptr<Room> GetStaircaseUp(int level);
	virtual ~Dungeon();
};

