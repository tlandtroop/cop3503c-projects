#include "Showroom.h"
#include <vector>
#include <iostream>
using namespace std;



float Showroom::GetInventoryValue() {
         float sum = 0;
         
         for (long unsigned int i = 0; i < vehicles.size(); i++) {
            sum += vehicles.at(i).GetPrice();
         }
         return sum;
      }
      
      
void Showroom::ShowInventory() {
         if (vehicles.size() == 0) {
            cout << "Unnamed Showroom is empty!" << endl;
         }
         else {
            cout << "Vehicles in " << name << endl;
            for (long unsigned int i = 0; i < vehicles.size(); i++) {
               vehicles.at(i).Display();
            }
         }
      }
      
void Showroom::AddVehicle(Vehicle v) {
         long unsigned int numVehicles = vehicles.size();
         
         if (numVehicles == capacity) {
            cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
         }
         else {
            vehicles.push_back(v);
         }
      }