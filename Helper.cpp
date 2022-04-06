#include "Helper.h"

void Helper::PrintInventory(vector <unique_ptr<Equipment>>& inv)
{
	int index = 1;
	float totalWeight = 0;

	cout << "Items in inventory: " << endl;
	for (auto item : inv)
	{
		cout << index << " " << item->name << endl;;
		index++;
		totalWeight += item->weight;
	}

	cout << "Total weight of inventory: " << totalWeight << endl << endl;
}

void Helper::AddArmorToInventory(vector <unique_ptr<Equipment>>& inv)
{
	string name;
	int AC;
	float weight;

	cout << "Give armor name: ";
	cin >> name;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "Give armor Armor class: ";
	cin >> AC;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "Give armor weight: ";
	cin >> weight;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');

	Armor newArmor(name, AC, weight);

	inv.push_back(newArmor);

	cout << newArmor.name << " has been added to inventory" << endl;

}

void Helper::AddWeaponToInventory(vector <unique_ptr<Equipment>>& inv)
{
	string name;
	int damage;
	float weight;

	cout << "Give weapon name: ";
	cin >> name;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "Give weapon damage: ";
	cin >> damage;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "Give weapon weight: ";
	cin >> weight;
	cin.clear();
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');

	//make_unique<Weapon>(name, damage, weight);

	inv.push_back(make_unique<Weapon>(name, damage, weight));

	cout << name << " has been added to inventory" << endl;

}

void Helper::RemoveItemFromIndex(vector <unique_ptr<Equipment>>& inv, int index)
{
	if (index <= 0 || index > inv.size())
	{
		cout << "Invalid value!" << endl;
	}
	else
	{ 
		cout << "Removed " << inv[index - 1]->name << " from inventory" << endl << endl;
		inv.erase(inv.begin() + (index-1));
	}
}


