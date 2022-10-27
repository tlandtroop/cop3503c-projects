#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "extrafile.h"
using namespace std;

int LoadShipFile(vector<Ship> &ships, string path, int counter)
{
    ifstream File(path, ios_base::binary);

    unsigned int count;
    File.read((char *)&count, sizeof(count));
    for (unsigned int i = 0; i < count; i++)
    {
        // Read name string
        string shipName;
        unsigned int length;
        File.read((char *)&length, sizeof(length));

        char *temporary = new char[length];
        File.read(temporary, length);
        shipName = temporary;
        delete[] temporary;

        // Read class string
        string shipClass;
        File.read((char *)&length, sizeof(length));

        temporary = new char[length];
        File.read(temporary, length);
        shipClass = temporary;
        delete[] temporary;

        // Read length, shield capacity, and max warp speed integers
        short lengthShip;
        File.read((char *)&lengthShip, sizeof(lengthShip));
        int shieldCapacity;
        File.read((char *)&shieldCapacity, sizeof(shieldCapacity));
        float warpSpeed;
        File.read((char *)&warpSpeed, sizeof(warpSpeed));

        Ship ship(shipName, shipClass, lengthShip, shieldCapacity, warpSpeed);
        ships.push_back(ship);

        // Read inventory
        unsigned int weaponCount;
        File.read((char *)&weaponCount, sizeof(weaponCount));
        for (unsigned int j = 0; j < weaponCount; j++)
        {
            File.read((char *)&length, sizeof(length));
            temporary = new char[length];
            File.read(temporary, length);
            string weaponName = temporary;
            delete[] temporary;

            int weaponInt;
            File.read((char *)&weaponInt, sizeof(weaponInt));
            float weaponFloat;
            File.read((char *)&weaponFloat, sizeof(weaponFloat));

            Ship::Weapons weapon = Ship::Weapons(weaponName, weaponInt, weaponFloat);
            ships[counter].GetWeaponsList().push_back(weapon);
        }
        counter++;
    }
    return counter;
}

void PrintAllShips(vector<Ship> &ships)
{
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        ships[i].DisplayShip();
    }
}

void PrintStrongestWeapon(vector<Ship> &ships)
{
    int strongestPower = 0;
    int index;
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        for (unsigned int j = 0; j < ships[i].GetWeaponsList().size(); j++)
        {
            if (ships[i].GetWeaponsList()[j].powerRatingC > strongestPower)
            {
                strongestPower = ships[i].GetWeaponsList()[j].powerRatingC;
                index = i;
            }
        }
    }
    ships[index].DisplayShip();
}

void PrintStrongestStarship(vector<Ship> &ships)
{
    int strongest = 0;
    int index;
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships[i].TotalPowerConsumption() > strongest)
        {
            strongest = ships[i].TotalPowerConsumption();
            index = i;
        }
    }
    ships[index].DisplayShip();
}

void PrintWeakestShip(vector<Ship> &ships)
{
    int weakest = ships[0].TotalPowerConsumption();
    int index = 0;
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships[i].GetWeaponsList().size() != 0)
        {
            if (ships[i].TotalPowerConsumption() < weakest)
            {
                weakest = ships[i].TotalPowerConsumption();
                index = i;
            }
        }
    }
    ships[index].DisplayShip();
}

void PrintUnarmedShips(vector<Ship> &ships)
{
    for (unsigned int i = 0; i < ships.size(); i++)
    {
        if (ships[i].GetWeaponsList().size() == 0)
        {
            ships[i].DisplayShip();
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
    int counter = 0;
    vector<Ship> ships;
    /* Load files here */
    switch (option)
    {
    case 1:
        LoadShipFile(ships, "friendlyships.shp", counter);
        break;
    case 2:
        LoadShipFile(ships, "enemyships.shp", counter);
        break;
    case 3:
        counter = LoadShipFile(ships, "friendlyships.shp", counter);
        LoadShipFile(ships, "enemyships.shp", counter);
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