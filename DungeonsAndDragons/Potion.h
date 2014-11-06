#pragma once
#include "Item.h"
class Potion :
	public Item
{
private: 
	int HpIncrement;

protected:
	void GenerateItem(int itemNumber, int itemLevel);

public:
	Potion();
	Potion(int floor);
	Potion(int itemNumber, int itemLevel);
	virtual ~Potion();

	int GetHpIncrement();
};

