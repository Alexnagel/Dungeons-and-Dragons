#pragma once
#include "Item.h"
class Weapon :
	public Item
{
private:
	bool equiped;

public:
	Weapon();
	virtual ~Weapon();

	// Functions
	void Equiped(bool p_equiped);
	bool IsEquiped();
};

