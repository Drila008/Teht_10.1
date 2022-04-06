#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;


void Character::EquipItem(int index)
{
	if (inventory[index - 1]->itemType == Equipment::Type::WEAPON)
	{
		float tWeight;
		int tDmg;
		string tName;

		inventory.push_back(equippedWpn);
		cout << "Placed " << equippedWpn->name << " in inventory" << endl;
		tName = inventory[index - 1]->name;
		tWeight = inventory[index - 1]->weight;
		tDmg = inventory[index - 1]->GetStat();

		//Weapon tWpn(tName, tWeight, tDmg);
		equippedWpn = make_unique<Weapon>(tName, tWeight, tDmg);
		cout << "Equipped " << tName << endl;
		inventory.erase(inventory.begin() + index-1);
		
		//equippedWpn = inventory[index - 1];
	}
	else
	{
		string tName = inventory[index - 1]->name;
		float bWeight;
		int bAC;
		string bName;

		inventory.push_back(equippedArmor);
		cout << "Placed " << equippedArmor->name << " in inventory" << endl;
		bName = inventory[index - 1]->name;
		bWeight = inventory[index - 1]->weight;
		bAC = inventory[index - 1]->GetStat();

		Armor bArmor(bName, bWeight, bAC);
		equippedArmor = make_unique<Armor>(bName, bWeight, bAC);
		cout << "Equipped " << bName << endl;
		inventory.erase(inventory.begin() + index-1);
	}
}

Character::Character(string _name, int _hp, int _str, unique_ptr<Weapon> _wpn, unique_ptr<Armor> _armor)
{
	name = _name;
	hp = _hp;
	strength = _str;
	equippedWpn = _wpn;
	equippedArmor = _armor;
}

void Character::PrintEquippedItems()
{
	cout << "Currently equipped weapon: " << equippedWpn->name << endl;
	cout << "Currently equipped armor: " << equippedArmor->name << endl;
}