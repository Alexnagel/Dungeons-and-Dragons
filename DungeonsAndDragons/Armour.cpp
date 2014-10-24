#include "stdafx.h"
#include "Armour.h"


Armour::Armour()
{
}


Armour::~Armour()
{
}

// Functions
void Armour::Equiped(bool p_equiped)
{
	equiped = p_equiped;
}

bool Armour::IsEquiped()
{
	return equiped;
}