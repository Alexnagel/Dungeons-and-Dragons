#pragma once
#include <string>
#include <iostream>
#include <array>
#include "RoomElements.h"

class Room
{
private:
	RoomElements roomElements;
	std::string description;

	virtual void GenerateDescription();
public:
	Room();
	virtual ~Room();
	Room* roomLeft;
	Room* roomRight;
	Room* roomTop;
	Room* roomBottom;
	bool roomIsVisited;

	std::string GetDescription();
	std::array<bool, 2> GetConnections();
};

