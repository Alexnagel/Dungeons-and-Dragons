#include "stdafx.h"
#include "GameManager.h"
#include "DungeonGenerator.h"

using namespace std;

default_random_engine GameManager::random;

GameManager::GameManager()
{
	DungeonGenerator generator;
	generator.CreateDungeon();

}

GameManager::~GameManager()
{
}
