#include "Helper.h"

void Helper::PrintInventory(vector<Equipment> inv)
{
	int index = 1;
	float totalWeight = 0;

	cout << "Items in inventory: " << endl;
	for (Equipment item : inv)
	{
		cout << index << " " << item.name << endl;;
		index++;
		totalWeight += item.weight;
	}

	cout << "Total weight of inventory: " << totalWeight << endl << endl;
}

void Helper::AddArmorToInventory(vector<Equipment>& inv)
{
	string name;
	int AC;
	float weight;

	cout << "Give armor name: ";
	cin >> name;
	cout << "Give armor Armor class: ";
	cin >> AC;
	cout << "Give armor weight: ";
	cin >> weight;

	Armor newArmor(name, AC, weight);

	inv.push_back(newArmor);

	cout << newArmor.name << " has been added to inventory" << endl;

}

void Helper::AddWeaponToInventory(vector<Equipment>& inv)
{
	string name;
	int damage;
	float weight;

	cout << "Give weapon name: ";
	cin >> name;
	cout << "Give weapon damage: ";
	cin >> damage;
	cout << "Give weapon weight: ";
	cin >> weight;

	Weapon newWeapon(name, damage, weight);

	inv.push_back(newWeapon);

	cout << newWeapon.name << " has been added to inventory" << endl;

}

void Helper::RemoveItemFromIndex(vector<Equipment>& inv, int index)
{
	if (index <= 0 || index > inv.size())
	{
		cout << "Invalid value!" << endl;
	}
	else
	{ 
		cout << "Removed " << inv[index - 1].name << " from inventory" << endl << endl;
		inv.erase(inv.begin() + (index-1));
	}
}


