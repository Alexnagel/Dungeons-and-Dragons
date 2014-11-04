#pragma once
#include <memory>
#include "Room.h"

class Floor
{
private:
	std::vector<std::vector<std::shared_ptr<Room>>> vFloor;
public:
	Floor();
	Floor(std::vector<std::vector<std::shared_ptr<Room>>> floorVector);
	
	std::string PrintFloor();
	std::shared_ptr<Room> GetRoom(int x, int y);
	std::shared_ptr<Room> GetStartRoom();
	
	virtual ~Floor();
};

