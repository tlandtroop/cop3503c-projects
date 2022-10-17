#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
#pragma once
using namespace std;

class Showroom {
   public:
      string name;
      vector<Vehicle> vehicles;
      long unsigned int capacity;
   
      Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0) {
         this->name = name;
         this->capacity = capacity;
      }
      
      vector<Vehicle> GetVehicleList() {
         return vehicles;
      }
      
      void AddVehicle(Vehicle v);
      
      void ShowInventory();
      
      float GetInventoryValue();
};