#include "stdafx.h"
#include "Room.h"

Room::Room()
{
}

std::string Room::GetDescription()
{

}

void Room::GenerateDescription()
{
	std::string size = roomElements.GetRandomSize();
	std::string floor = roomElements.GetRandomFloorType();
	std::string item = roomElements.GetRandomItem();
	std::string place = roomElements.GetRandomPlace();
	std::string lighting = roomElements.GetRandomLighting();

	char buffer[1024];
	sprintf_s(buffer, sizeof(buffer), "You've entered a %s %s room, with a %s floor. You look around and see %s"

}

Room::~Room()
{
}
