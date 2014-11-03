#include "stdafx.h"
#include "Room.h"

Room::Room(int level)
{
	this->level = level;
	roomIsVisited = false;
	roomIsStart = false;

	roomTop = nullptr;
	roomRight = nullptr;
	roomBottom = nullptr;
	roomLeft = nullptr;

	GenerateDescription();
}

Room::Room()
{

}

bool Room::ContainsRoom(Direction direction)
{
	switch (direction)
	{
	case Direction::NORTH:
		if (roomTop != nullptr)
			return true;
		break;
	case Direction::EAST:
		if (roomRight != nullptr)
			return true;
		break;
	case Direction::SOUTH:
		if (roomBottom != nullptr)
			return true;
		break;;
	case Direction::WEST:
		if (roomLeft != nullptr)
			return true;
		break;
	}
}

Room* Room::GoInDirection(Direction direction)
{
	switch (direction)
	{
	case Direction::NORTH: return roomTop; break;
	case Direction::EAST:  return roomRight; break;
	case Direction::SOUTH: return roomBottom; break;
	case Direction::WEST:  return roomLeft; break;
	}
	return new Room();
}

std::string Room::Print()
{
	if (directions.empty())
		SetDirections();

	return description + "\n" + directions;
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
	directions = "You can go in the following directions: ";

	if (roomTop != nullptr)
		directions += "north, ";
	if (roomRight != nullptr)
		directions += "east, ";
	if (roomBottom != nullptr)
		directions += "south, ";
	if (roomLeft != nullptr)
		directions += "west";
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
	sprintf_s(buffer, sizeof(buffer), "You've entered a %s %s size room, with a %s floor. It is lit by %s. You look around and see %s in %s", 
		state.c_str(), size.c_str(), floor.c_str(), lighting.c_str(), item.c_str(), place.c_str());
	description = buffer;
}

/*
	Get the room connections for generating the map
*/
std::array<bool, 2> Room::GetConnections()
{
	std::array<bool, 2> connections{ { (roomTop != nullptr), (roomLeft != nullptr) } };
	return connections;
}

Room::~Room()
{
	/*
	delete roomTop;
	delete roomRight;
	delete roomBottom; 
	delete roomLeft;
	roomTop = nullptr;
	roomRight = nullptr;
	roomBottom = nullptr;
	roomLeft = nullptr;*/
}
