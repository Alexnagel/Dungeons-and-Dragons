#include "stdafx.h"
#include "Room.h"

Room::Room(int level)
{
	this->level = level;
	roomIsVisited = false;
	roomIsStart = false;
	hasTrap = false;

	roomTop = std::weak_ptr<Room>();
	roomRight = std::weak_ptr<Room>();
	roomBottom = std::weak_ptr<Room>();
	roomLeft = std::weak_ptr<Room>();

	GenerateDescription();
}

Room::Room(int level, bool isStart)
{
	this->level = level;
	roomIsVisited = false;
	hasTrap = false;

	roomTop = std::weak_ptr<Room>();
	roomRight = std::weak_ptr<Room>();
	roomBottom = std::weak_ptr<Room>();
	roomLeft = std::weak_ptr<Room>();

	GenerateDescription();
	SetStart();
}

Room::Room() : roomTop(std::weak_ptr<Room>()), roomRight(std::weak_ptr<Room>()), roomBottom(std::weak_ptr<Room>()), roomLeft(std::weak_ptr<Room>())
{
}

Room& Room::operator=(const Room& other)
{
	if (this != &other)
	{
		Room* cSymbol = new Room(other);
		return *cSymbol;

	}
	return *this;
}

bool Room::ContainsRoom(Direction direction)
{
	switch (direction)
	{
	case Direction::NORTH:
		if (!roomTop.expired())
			return true;
		break;
	case Direction::EAST:
		if (!roomRight.expired())
			return true;
		break;
	case Direction::SOUTH:
		if (!roomBottom.expired())
			return true;
		break;;
	case Direction::WEST:
		if (!roomLeft.expired())
			return true;
		break;
	}
	return false;
}

std::shared_ptr<Room> Room::GoInDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::NORTH: return std::shared_ptr<Room>(roomTop.lock()); break;
	case Direction::EAST:  return std::shared_ptr<Room>(roomRight.lock()); break;
	case Direction::SOUTH: return std::shared_ptr<Room>(roomBottom.lock()); break;
	case Direction::WEST:  return std::shared_ptr<Room>(roomLeft.lock()); break;
	}
	return std::make_shared<Room>();
}

std::string Room::Print()
{
	if (directions.empty())
		SetDirections();

	return description + "\n" + directions;
}

std::string Room::PrintChest()
{
	return std::string();
}

Item Room::GetChestItem(std::string itemName)
{
	return Item();
}

bool Room::HasTrap()
{
	return hasTrap;
}

bool Room::HasChest()
{
	return false;
}

Trap Room::GetTrap()
{
	return trap;
}

std::string Room::RoomCharacter()
{
	return "x";
}

std::string Room::GetDirections()
{
	return directions;
}

void Room::SetDirections()
{
	directions = "Possible directions:";

	if (!roomTop.expired())
		directions += " north,";
	if (!roomRight.expired())
		directions += " east,";
	if (!roomBottom.expired())
		directions += " south,";
	if (!roomLeft.expired())
		directions += " west";

	if (directions.back() == char(','))
		 directions.pop_back();
}

void Room::SetStart()
{
	roomIsStart = true;
}

bool Room::GetStart()
{
	return roomIsStart;
}

void Room::SetVisited()
{
	roomIsVisited = true;
}

bool Room::IsVisited()
{
	return roomIsVisited;
}

/*
	Generate a random description for the room
*/
void Room::GenerateDescription()
{
	std::string size	 = roomElements.GetRandomSize();
	std::string state	 = roomElements.GetRandomState();
	std::string floor	 = roomElements.GetRandomFloorType();
	std::string item	 = roomElements.GetRandomItem();
	std::string place	 = roomElements.GetRandomPlace();
	std::string lighting = roomElements.GetRandomLighting();

	char buffer[512];
	sprintf_s(buffer, sizeof(buffer), "You've entered a %s %s size room, with a %s floor. It is lit by %s. You look around and see %s in %s.", 
		state.c_str(), size.c_str(), floor.c_str(), lighting.c_str(), item.c_str(), place.c_str());
	description = buffer;
}

/*
	Get the room connections for generating the map
*/
std::array<bool, 2> Room::GetConnections()
{
	std::array<bool, 2> connections{ { !roomTop.expired(), !roomLeft.expired() } };
	return connections;
}

std::vector<std::shared_ptr<Enemy>> Room::GetEnemies()
{
	return std::vector<std::shared_ptr<Enemy>>();
}

void Room::DefeatedEnemies()
{
}

Room::~Room()
{
	roomTop.reset();
	roomRight.reset();
	roomBottom.reset();
	roomLeft.reset();
}
