#pragma once
#include "Item.h"
class Armour :
	public Item
{
private:
	bool equiped;

protected:
	void GenerateItem(int itemNumber, int itemLevel);

public:
	Armour();
	Armour(int floor);
	Armour(int itemNumber, int itemLevel);
	virtual ~Armour();

	// Functions
	void Equiped(bool p_equiped);
	bool IsEquiped();
};

