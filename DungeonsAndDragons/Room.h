#pragma once
#include <string>
#include "RoomElements.h"

class Room
{
private:
	RoomElements roomElements;
	std::string description;

	void GenerateDescription();
public:
	Room();
	virtual ~Room();

	std::string GetDescription();
};

