#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Color
{
    map<int, char> nums = {
        {10, 'A'},
        {11, 'B'},
        {12, 'C'},
        {13, 'D'},
        {14, 'E'},
        {15, 'F'},
    };

    string name;
    int value;
    vector<int> hex;

    public:
        Color(string name, int value);

        // Accessors
        unsigned char GetR() const;
        unsigned char GetG() const;
        unsigned char GetB() const;
        string GetHexValue() const;
        string GetName() const;
        int HexToDecimal(int color) const;
        
};