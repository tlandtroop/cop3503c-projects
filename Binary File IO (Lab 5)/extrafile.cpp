#include "extrafile.h"
#include <vector>
#include <iostream>
using namespace std;

// Ship constructor definition
Ship::Ship(string name, string className, short length, int shieldCapacity, float warpSpeed)
{
    nameC = name;
    classNameC = className;
    lengthC = length;
    shieldCapacityC = shieldCapacity;
    warpSpeedC = warpSpeed;
}

// Weapons constructor definition
Ship::Weapons::Weapons(string weaponName, int powerRating, float powerConsumption)
{
    weaponNameC = weaponName;
    powerRatingC = powerRating;
    powerConsumptionC = powerConsumption;
}

// Gets all the data of the ship
void Ship::DisplayShip()
{
    int totalFirepower = 0;

    cout << "Name: " << nameC << endl;
    cout << "Class: " << classNameC << endl;
    cout << "Length: " << lengthC << endl;
    cout << "Shield capacity: " << shieldCapacityC << endl;
    cout << "Maximum Warp: " << warpSpeedC << endl;
    cout << "Armaments: " << endl;

    if (shipWeapons.size() == 0)
    {
        cout << "Unarmed" << endl;
    }
    else
    {
        for (unsigned int i = 0; i < shipWeapons.size(); i++)
        {
            totalFirepower += shipWeapons[i].powerRatingC;
            cout << shipWeapons[i].weaponNameC << ", " << shipWeapons[i].powerRatingC << ", " << shipWeapons[i].powerConsumptionC << endl;
        }
        cout << "Total firepower: " << totalFirepower << endl;
    }
}

// Gets total power consumption of the weapons in the ship
int Ship::TotalPowerConsumption()
{
    int totalPowerConsumption = 0;

    for (unsigned int i = 0; i < shipWeapons.size(); i++)
    {
        totalPowerConsumption += shipWeapons[i].powerRatingC;
    }
    return totalPowerConsumption;
}

vector<Ship::Weapons> &Ship::GetWeaponsList()
{
    return shipWeapons;
}
