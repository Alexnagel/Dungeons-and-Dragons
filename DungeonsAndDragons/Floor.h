#pragma once
#include <memory>
#include "Room.h"
#include "Staircase.h"

class Floor
{
private:
	std::vector<std::vector<std::shared_ptr<Room>>> vFloor;
	Floor& operator=(const Floor& other);

public:
	Floor();
	Floor(std::vector<std::vector<std::shared_ptr<Room>>> floorVector);
	
	std::string PrintFloor();
	std::shared_ptr<Room> GetRoom(int x, int y);
	std::shared_ptr<Room> GetStartRoom();
	std::shared_ptr<Room> GetStaircaseDown();
	std::shared_ptr<Room> GetStaircaseUp();
	
	virtual ~Floor();
};

