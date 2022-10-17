#include <iostream>
#include <vector>
#include <string>
#include "Showroom.h"
#pragma once
using namespace std;

class Dealership {
   public:
      string name;
      vector<Showroom> showrooms;
      long unsigned int capacity;
   
      Dealership(string name = "Generic Dealership", unsigned int capacity = 0) {
         this->name = name;
         this->capacity = capacity;
      }
      
      void AddShowroom(Showroom s);
      
      void ShowInventory();
      
      float GetAveragePrice();
};