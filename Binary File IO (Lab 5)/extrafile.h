#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ship
{
public:
    struct Weapons
    {
        string weaponNameC;
        int powerRatingC;
        float powerConsumptionC;
        Weapons(string weaponNameC, int powerRatingC, float powerConsumptionC);
    };
    string nameC;
    string classNameC;
    short lengthC;
    int shieldCapacityC;
    float warpSpeedC;
    vector<Weapons> shipWeapons;

    Ship(string name, string className, short length, int shieldCapacity, float warpSpeed);
    void DisplayShip();
    int TotalPowerConsumption();
    vector<Weapons> &GetWeaponsList();
};