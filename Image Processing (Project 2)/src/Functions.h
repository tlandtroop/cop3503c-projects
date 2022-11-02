#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Image.h"
using namespace std;

float scaleValue(float scale);

unsigned int clamp(int result);

Image Multiply(Image &A, Image &B);