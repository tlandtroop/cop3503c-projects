#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Image.h"
using namespace std;

float scale(float scale);

unsigned int clamp(int result);

float screenAlgo(float factor, unsigned int A, unsigned int B);

bool backgroundColor(unsigned int background);

Image Multiply(Image &A, Image &B);

Image Subtract(Image &A, Image &B);

Image Screen(Image &A, Image &B);

Image Overlay(Image &A, Image &B);

Image addGreen(Image &A);

Image scaleRed(Image &A);

Image splitChannels(string rgb, Image &A);

Image Combine(Image &A, Image &B, Image &C);

Image Rotate(Image &A);