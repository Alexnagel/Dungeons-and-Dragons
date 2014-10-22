#include "stdafx.h"
#include "Room.h"

Room::Room()
{
	roomIsVisited = false;

	roomTop = nullptr;
	roomRight = nullptr;
	roomBottom = nullptr;
	roomLeft = nullptr;

	GenerateDescription();
}

std::string Room::GetDescription()
{
	return description;
}

void Room::GenerateDescription()
{
	/*
	std::string size = roomElements.GetRandomSize();
	std::string floor = roomElements.GetRandomFloorType();
	std::string item = roomElements.GetRandomItem();
	std::string place = roomElements.GetRandomPlace();
	std::string lighting = roomElements.GetRandomLighting();

	char buffer[1024];
	sprintf_s(buffer, sizeof(buffer), "You've entered a %s %s room, with a %s floor. You look around and see %s");
	description = buffer;
	*/
}

std::array<bool, 2> Room::GetConnections()
{
	std::array<bool, 2> connections{ { (roomTop != nullptr), (roomLeft != nullptr) } };
	return connections;
}

Room::~Room()
{
	/*delete roomTop;
	delete roomRight;
	delete roomBottom; 
	delete roomLeft;
	roomTop = nullptr;
	roomRight = nullptr;
	roomBottom = nullptr;
	roomLeft = nullptr;*/
}
