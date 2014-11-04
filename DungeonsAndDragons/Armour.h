#pragma once
#include "Item.h"
class Armour :
	public Item
{
private:
	bool equiped;

public:
	Armour();
	Armour(int floor);
	virtual ~Armour();

	// Functions
	void Equiped(bool p_equiped);
	bool IsEquiped();
};

