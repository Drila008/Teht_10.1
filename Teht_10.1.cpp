// Teht_10.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Helper.h"

using namespace Helper;
using namespace std;

bool isRunning = true;
char input;

int main()
{
    //Create player
    Character player("SuperSeppo", 10, 5, make_unique<Weapon>("Dagger", 1.5, 3), make_unique<Armor>("LeatherTunic", 3, 2));
    //Create and put to inventory a starting item for easy testing
    player.inventory.push_back(make_unique<Weapon>("puukko", 3, 3));

    while (isRunning)
    {

        cout << "Choose action:" << endl;
        cout << "1: Add item to inventory" << endl;
        cout << "2: Remove item from index in inventory" << endl;
        cout << "3: Equip item from index" << endl;
        cout << "4: Print inventory and equipped items" << endl;
        cout << "Q: Quit program" << endl;


        cin >> input;
        cin.clear(); //Clear and ignore inputs so stuff wont get messed up, also change to upper so only need to check that
        cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        input = toupper(input);
        switch (input)
        {
        default:
            cout << "Invalid input" << endl;
            break;

        case '1':
            cout << "Select item to add: W for weapon or A for armor: ";
            cin >> input;
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
            input = toupper(input);
            if (input == 'W')
            {
                Helper::AddWeaponToInventory(player.inventory);
            }
            if(input == 'A' )
            {
                Helper::AddArmorToInventory(player.inventory);
            }
            else
            {
                cout << "Invalid input!" << endl;
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
            
        case 'Q':
            isRunning = false;
            break;
        }

    }
    if(isRunning)
         Helper::PrintInventory(player.inventory);
}

