#pragma once
#include <string>
#include <iostream>
#include <array>
#include "RoomElements.h"
#include "Direction.h"

class Room
{
private:
	bool roomIsVisited;

protected:
	int level;
	std::string description;
	std::string directions;
	RoomElements roomElements;
	bool roomIsStart;

	void SetDirections();
	virtual void GenerateDescription();

public:
	Room* roomLeft;
	Room* roomRight;
	Room* roomTop;
	Room* roomBottom;

	Room& operator=(const Room& other);

	Room(int level);
	Room();
	virtual ~Room();

	std::array<bool, 2> GetConnections();
	std::string GetDirections();
	Room* GoInDirection(Direction direction);
	bool ContainsRoom(Direction direction);

	void SetVisited();
	bool IsVisited();

	void SetStart();
	bool GetStart();
	virtual std::string Print();
	virtual std::string RoomCharacter();
};

