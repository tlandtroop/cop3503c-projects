#include "Functions.h"
#include "Image.h"
#include <fstream>
using namespace std;

float scaleValue(float scale)
{
    scale += 0.5f;
    return scale;
}

unsigned int clamp(int before)
{
    unsigned int clamped;

    if (before < 0)
    {
        clamped = 0;
    }
    else if (before > 255)
    {
        clamped = 255;
    }
    else
    {
        clamped = before;
    }
    return clamped;
}

Image Multiply(Image &A, Image &B)
{
    Image C;

    Image::Header header = A.getHeader();
    C.setHeader(header);
    A.setUnsignedInts();
    B.setUnsignedInts();

    vector<Pixel> Apixels = A.getPixelVector();
    vector<Pixel> Bpixels = B.getPixelVector();

    vector<Pixel> Cpixels;

    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Cpixel;

        unsigned int redInt = (unsigned int)(scaleValue(Apixels[i].redInt * Bpixels[i].redInt / 255.0f));
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        unsigned int greenInt = (unsigned int)(scaleValue(Apixels[i].greenInt * Bpixels[i].greenInt / 255.0f));
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        unsigned int blueInt = (unsigned int)(scaleValue(Apixels[i].blueInt * Bpixels[i].blueInt / 255.0f));
        unsigned char blue = A.ConvertItoC(blueInt);
        Cpixel.blue = blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}
