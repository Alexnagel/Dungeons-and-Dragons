#include "stdafx.h"
#include "RoomElements.h"

RoomElements::RoomElements()
{
	seed = std::random_device()();
	rng  = std::mt19937(seed);
	fillVectors();
}

void RoomElements::fillVectors()
{
	// Room sizes
	sizeVector.push_back("small");
	sizeVector.push_back("big");
	sizeVector.push_back("average");

	// Room states
	stateVector.push_back("clean");
	stateVector.push_back("dirty");
	stateVector.push_back("dusty");

	// Room lightings
	lightingVector.push_back("candles");
	lightingVector.push_back("torches");
	lightingVector.push_back("a fireplace");
	lightingVector.push_back("a chandelier");

	// Room items 
	itemVector.push_back("a table with four chairs");
	itemVector.push_back("a broken table");
	itemVector.push_back("a bed");
	itemVector.push_back("a cabinet");
	itemVector.push_back("a fireplace");
	itemVector.push_back("a shrine");
	itemVector.push_back("a coffin");
	itemVector.push_back("a sword rack");
	itemVector.push_back("a skull");
	itemVector.push_back("bones");
	itemVector.push_back("mushrooms");
	itemVector.push_back("a pile of rocks");
	itemVector.push_back("an enchantment table");
	itemVector.push_back("an anvil");

	// Room floor types
	floorVector.push_back("stone");
	floorVector.push_back("grass");
	floorVector.push_back("wooden");
	floorVector.push_back("sand");

	// Item places
	placeVector.push_back("the right corner");
	placeVector.push_back("the middle of the room");
	placeVector.push_back("the left corner");
}

std::string RoomElements::GetRandomFloorType()
{
	return std::string((floorVector[GetRandomNumber(floorVector.size())]));
}

std::string RoomElements::GetRandomSize()
{
	return sizeVector[GetRandomNumber(sizeVector.size())];
}

std::string RoomElements::GetRandomLighting()
{
	return lightingVector[GetRandomNumber(lightingVector.size())];
}

std::string RoomElements::GetRandomState()
{
	return stateVector[GetRandomNumber(stateVector.size())];
}

std::string RoomElements::GetRandomItem()
{
	return itemVector[GetRandomNumber(itemVector.size())];
}

std::string RoomElements::GetRandomPlace()
{
	return placeVector[GetRandomNumber(placeVector.size())];
}

int RoomElements::GetRandomNumber(int max)
{
	return std::uniform_int_distribution<int>(0, max - 1)(rng);
}

RoomElements::~RoomElements()
{
}
