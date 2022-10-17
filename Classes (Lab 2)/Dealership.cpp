#include "Dealership.h"
#include <vector>
#include <iostream>
using namespace std;

void Dealership::AddShowroom(Showroom s) {
         long unsigned int numShowrooms = showrooms.size();
         
         // If dealership is full, throw error.
         if (numShowrooms == capacity) {
            cout << "Dealership is full, can't add another showroom!" << endl;
         }
         // If dealership isn't full yet, add another showroom
         else {
            showrooms.push_back(s);
         }
      }
      
float Dealership::GetAveragePrice() {
   // count of vehicles in showrooms
   long unsigned int count = 0;
   // sum of all the prices of the vehicles
   float sum = 0;
   
   
   // loop through all showrooms and all vehicles in each showroom
   for (long unsigned int i = 0; i < showrooms.size(); i++) {
      vector<Vehicle> vehicles = showrooms.at(i).GetVehicleList();
      for (long unsigned int j = 0; j < vehicles.size(); j++) {
         sum += vehicles.at(j).GetPrice();
         count++;
      }
   }
   if (count == 0) {
      return 0.0f;
   } else {
      return sum / count;
   }
   
}

void Dealership::ShowInventory() {
   for (long unsigned int i = 0; i < showrooms.size(); i++) {
      showrooms.at(i).ShowInventory();
      cout << endl;
   }
   if (showrooms.size() == 0) {
      cout << "Generic Dealership is empty!" << endl;
   }
   
   cout << "Average car price: $" << GetAveragePrice();
}