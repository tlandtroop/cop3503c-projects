#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Inventory
{
    string name;
    int weaponInt;
    float weaponFloat;
};

struct Ship
{
    string name, ship_class;
    short length;
    int shieldCapacity;
    float maxWarpSpeed;
    vector<Inventory> inventory;
};

void DisplayShip(Ship &ship)
{
    int totalFirepower;
    cout << "Name: " << ship.name << endl;
    cout << "Class: " << ship.ship_class << endl;
    cout << "Length: " << ship.length << endl;
    cout << "Shield Capacity: " << ship.shieldCapacity << endl;
    cout << "Maximum Warp: " << ship.maxWarpSpeed << endl;
    cout << "Armaments: " << endl;

    if (ship.inventory.size() != 0)
    {
        for (unsigned int i = 0; i < ship.inventory.size(); i++)
        {
            cout << ship.inventory.at(i).name << ", " << ship.inventory.at(i).weaponInt << ", " << ship.inventory.at(i).weaponFloat << endl;
            totalFirepower += ship.inventory.at(i).weaponInt;
        }
    }
    else
    {
        cout << "Unarmed" << endl;
    }
    cout << "Total firepower: " << totalFirepower << endl;
    cout << endl;
}

void LoadShipFile(vector<Ship> &ships, int fileNumber)
{
    string path;
    if (fileNumber == 1)
    {
        path == "./friendlyships.shp";
    }
    else if (fileNumber == 2)
    {
        path == "./enemyships.shp";
    }

    ifstream File(path, ios_base::binary);

    if (File.is_open())
    {
        cout << "File has been opened";
        int count;
        File.read((char *)&count, 4);

        for (int i = 0; i < count; i++)
        {
            Ship ship;
            int nameLen;
            int weaponCount;

            File.read((char *)&nameLen, 4);

            char *name = new char[nameLen];
            for (int i = 0; i < nameLen; i++)
            {
                File.read(&name[i], 1);
            }
            ship.name = name;
            delete name;

            File.read((char *)&ship.ship_class, 4);
            File.read((char *)&ship.length, 2);
            File.read((char *)&ship.shieldCapacity, 4);
            File.read((char *)&ship.maxWarpSpeed, 4);

            File.read((char *)&weaponCount, 4);
            if (weaponCount > 0)
            {
                Inventory inventory;
                for (int i = 0; i < weaponCount; i++)
                {
                    File.read((char *)&nameLen, 4);

                    char *name = new char[nameLen];
                    for (int i = 0; i < nameLen; i++)
                    {
                        File.read(&name[i], 1);
                    }
                    inventory.name = name;
                    delete name;

                    File.read((char *)&inventory.weaponInt, 4);
                    File.read((char *)&inventory.weaponFloat, 4);

                    ship.inventory.push_back(inventory);
                }
            }
            ships.push_back(ship);
        }
        File.close();
    }
}

void PrintAllShips(vector<Ship> &ships)
{
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        DisplayShip(ships.at(i));
    }
}

void PrintStrongestWeapon(vector<Ship> &ships)
{
    Ship strongestWeapon = ships.at(0);
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships.at(i).inventory.at(i).weaponInt > strongestWeapon.inventory.at(i).weaponInt)
        {
            strongestWeapon = ships.at(i);
        }
        DisplayShip(strongestWeapon);
    }
}

void PrintStrongestStarship(vector<Ship> &ships)
{
    Ship strongest = ships.at(0);
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships.at(i).inventory.at(i).weaponInt > strongest.inventory.at(i).weaponInt)
        {
            strongest = ships.at(i);
        }
        DisplayShip(strongest);
    }
}

void PrintWeakestShip(vector<Ship> &ships)
{
    Ship weakest = ships.at(0);
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships.at(i).inventory.size() != 0)
        {
            if (ships.at(i).inventory.at(i).weaponInt < weakest.inventory.at(i).weaponInt)
            {
                weakest = ships.at(i);
            }
        }
    }
    DisplayShip(weakest);
}

void PrintUnarmedShips(vector<Ship> &ships)
{
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships.at(i).inventory.size() == 0)
        {
            DisplayShip(ships.at(i));
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    // Make vector of ships
    vector<Ship> ships;
    /* Load files here */
    switch (option)
    {
    case 1:
        LoadShipFile(ships, 1);
        break;
    case 2:
        LoadShipFile(ships, 2);
        break;
    case 3:
        LoadShipFile(ships, 1);
        LoadShipFile(ships, 2);
        break;
    default:
        break;
    }

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    /* Work your magic here */
    switch (option)
    {
    case 1:
        PrintAllShips(ships);
        break;
    case 2:
        PrintStrongestWeapon(ships);
        break;
    case 3:
        PrintStrongestStarship(ships);
        break;
    case 4:
        PrintWeakestShip(ships);
        break;
    case 5:
        PrintUnarmedShips(ships);
        break;
    default:
        break;
    }

    return 0;
}