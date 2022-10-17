#include <string>
#include <iostream>
#pragma once
using namespace std;

class Vehicle {
   std::string make;
   std::string model;
   unsigned int year;
   float price;
   unsigned int mileage;
   
   public:
      Vehicle() {
         make = "COP3503";
         model = "Rust Bucket";
         year = 1900;
         price = 0;
         mileage = 0;
      }
      
      Vehicle(std::string make, std::string model, int year, float price, int mileage) {
         this->make = make;
         this->model = model;
         this->year = year;
         this->price = price;
         this->mileage = mileage;
      }
      
      void Display() {
         cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;         
      }
      
      string GetYearMakeModel() {
         string yearMakeModel = to_string(year) + " " + make + " " + model;
         return yearMakeModel;
      }
      
      float GetPrice() {
         return price;  
      }
};