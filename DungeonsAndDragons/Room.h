#pragma once
#include <memory>
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
	bool roomIsStart;
	int level;
	std::string description;
	std::string directions;
	RoomElements roomElements;

	void SetDirections();
	virtual void GenerateDescription();

public:
	std::weak_ptr<Room> roomLeft;
	std::weak_ptr<Room> roomRight;
	std::weak_ptr<Room> roomTop;
	std::weak_ptr<Room> roomBottom;

	Room& operator=(const Room& other);

	Room(int level);
	Room(int level, bool isStart);
	Room();
	virtual ~Room();

	std::array<bool, 2> GetConnections();
	std::string GetDirections();
	std::shared_ptr<Room> GoInDirection(Direction direction);
	bool ContainsRoom(Direction direction);

	void SetVisited();
	bool IsVisited();

	void SetStart();
	bool GetStart();
	virtual std::string Print();
	virtual std::string RoomCharacter();
};

