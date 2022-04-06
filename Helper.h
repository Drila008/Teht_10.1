#pragma once
#include "Character.h"

namespace Helper
{
	void PrintInventory(vector<Equipment> inv);
	void AddArmorToInventory(vector<Equipment>& inv);
	void AddWeaponToInventory(vector<Equipment>& inv);
	void RemoveItemFromIndex(vector<Equipment>& inv, int index);
}