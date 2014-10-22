#include "stdafx.h"
#include "GameManager.h"

std::default_random_engine GameManager::random;

GameManager::GameManager()
{
	DungeonGenerator generator;
	generator.CreateDungeon();
}

GameManager::~GameManager()
{
	
}
