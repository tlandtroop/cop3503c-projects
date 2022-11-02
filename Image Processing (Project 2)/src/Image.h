#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Pixel
{
    unsigned char blue, green, red;
    unsigned int redInt, blueInt, greenInt;
};

class Image
{
public:
    struct Header
    {
        char idLength;
        char colorMapType;
        char dataTypeCode;
        short colorMapOrigin;
        short colorMapLength;
        char colorMapDepth;
        short xOrigin;
        short yOrigin;
        short width;
        short height;
        char bitsPerPixel;
        char imageDescriptor;
    };

    void LoadImage(string name);

    void WriteImage(string outName);

    unsigned int ConvertCtoI(unsigned char character);

    unsigned char ConvertItoC(unsigned int integer);

    void setUnsignedInts();

    Header getHeader();

    void setHeader(Header &headerData);

    vector<Pixel> getPixelVector();

    void setPixelVector(vector<Pixel> &vector);

    bool operator==(Image &other);

private:
    Header header;
    Pixel pixel;
    vector<Pixel> pixels;
};