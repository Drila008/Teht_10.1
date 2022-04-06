// Teht_10.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Helper.h"

using namespace Helper;
using namespace std;

enum class itemType {ARMOR, WEAPON};
itemType type;

char input;

int main()
{
    Character player("SuperSeppo", 10, 5, Weapon("Dagger", 1.5, 3), Armor("LeatherTunic", 3, 2));

    Weapon jee("puukko", 3, 3);
    player.inventory.push_back(jee);

    while (true)
    {

        cout << "Choose action:" << endl;
        cout << "1: Add item to inventory" << endl;
        cout << "2: Remove item from index in inventory" << endl;
        cout << "3: Equip item from index" << endl;
        cout << "4: Print inventory and equipped items" << endl;

        cin >> input;

        switch (input)
        {
        default:
            cout << "Invalid input" << endl;
            break;

        case '1':
            cout << "Select item to add: W for weapon or A for armor: ";
            cin >> input;
            if (input == 'w')
            {
                Helper::AddWeaponToInventory(player.inventory);
            }
            else
            {
                Helper::AddArmorToInventory(player.inventory);
            }
            break;

        case '2':
            int index;
            cout << "Give item index to remove: ";
            cin >> index;
            Helper::RemoveItemFromIndex(player.inventory, index);
            break;

        case '3':
            int index1;
            cout << "Give index of item to equip: ";
            cin >> index1;
            if (index1 == 0 || index1 > player.inventory.size())
            {
                cout << "Invalid input!" << endl << endl;
                break;
            }
            player.EquipItem(index1);

            break;

        case '4':
            player.PrintEquippedItems();
            Helper::PrintInventory(player.inventory);
            break;
            
        }

    }

    Helper::PrintInventory(player.inventory);
}

