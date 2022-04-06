#pragma once
#include "Character.h"

namespace Helper
{
	void PrintInventory(vector <unique_ptr<Equipment>>& inv);
	void AddArmorToInventory(vector <unique_ptr<Equipment>>& inv);
	void AddWeaponToInventory(vector <unique_ptr<Equipment>>& inv);
	void RemoveItemFromIndex(vector <unique_ptr<Equipment>>& inv, int index);
}