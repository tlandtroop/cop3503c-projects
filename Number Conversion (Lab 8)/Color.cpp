#include <string>
#include <iostream>
#include "Color.h"
using namespace std;

Color::Color(string colorName, int val) {
    name = colorName;
    value = val;
}


unsigned char Color::GetR() const {
    return HexToDecimal(0);
}

unsigned char Color::GetG() const {
    return HexToDecimal(1);
}

unsigned char Color::GetB() const {
    return HexToDecimal(2);
}

string Color::GetHexValue() const {
    string hexVal;
    vector<int> hexVector;
    int remainder;
    int quotient = value;
    while(quotient != 0) {
        remainder = quotient % 16;
        quotient /= 16;
        hexVector.push_back(remainder);
    }

    for (unsigned int i = 0; i < hexVector.size(); i++) {
        if (hexVector.at(i) > 9) {
            char x = nums.find(hexVector.at(i))->second;
            hexVal = x + hexVal;
        }
        else {
            hexVal = to_string(hexVector.at(i)) + hexVal;
        }
    }
    if (hexVal.length() < 6) {
        unsigned int y = 6 - hexVal.length();
        for (unsigned int i = 0; i < y; i++) {
            hexVal = to_string(0) + hexVal;
        }

    }

    hexVal = "0x" + hexVal;
    return hexVal;
}

string Color::GetName() const {
    return name;
}

int Color::HexToDecimal(int color) const {
    int first;
    int second;

    if (color == 0) {
        first = 2;
        second = 3;
    }
    else if (color == 1) {
        first = 4;
        second = 5;
    }
    else if (color == 2) {
        first = 6;
        second = 7;
    }

    char colorArray[2];
    int colorInts[2];
    colorArray[0] = GetHexValue().at(first);
    colorArray[1] = GetHexValue().at(second);

    for (int i = 0; i < 2; i++) {
        bool isChanged = false;
        map<int, char>::const_iterator iterator;
        for (iterator = nums.begin(); iterator != nums.end(); iterator++) {
            if (iterator->second == colorArray[i]) {
                colorInts[i] = iterator->first;
                isChanged = true;
            }
        }
        if (!isChanged) {
            colorInts[i] = colorArray[i] - 48;
        }
    }

    int C = (colorInts[0] * 16) + colorInts[1];
    return C;
    

}
