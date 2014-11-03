#pragma once
#include <string>
#include <iostream>
#include <array>
#include "RoomElements.h"
#include "Direction.h"

class Room
{
private:
	std::string description;
	std::string directions;
	bool roomIsVisited;

	void SetDirections();

protected:
	int level;
	RoomElements roomElements;

	virtual void GenerateDescription();

public:
	Room* roomLeft;
	Room* roomRight;
	Room* roomTop;
	Room* roomBottom;

	Room(int level);
	Room();
	virtual ~Room();
	std::array<bool, 2> GetConnections();
	Room GoInDirection(Direction direction);
	void SetVisited();
	bool IsVisited();
	virtual std::string Print();
	virtual std::string RoomCharacter();
};

