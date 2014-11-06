#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <array>
#include "RoomElements.h"
#include "Direction.h"
#include "Enemy.h"
#include "Item.h"
#include "Trap.h"

class Room
{
private:
	bool roomIsVisited;

protected:
	bool roomIsStart;
	int level;
	std::string description;
	std::string directions;
	bool hasTrap;
	Trap trap;
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

	bool HasTrap();
	Trap GetTrap();

	void SetStart();
	bool GetStart();
	virtual std::string Print();
	virtual std::string RoomCharacter();
	virtual std::vector<std::shared_ptr<Enemy>> GetEnemies();
	virtual void DefeatedEnemies();
	virtual std::string PrintChest();
	virtual Item GetChestItem(std::string itemName);
};

