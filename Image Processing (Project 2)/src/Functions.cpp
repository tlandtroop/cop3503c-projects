#include "Functions.h"
#include "Image.h"
#include <fstream>
using namespace std;

float scale(float scale)
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

float screenAlgo(float factor, unsigned int A, unsigned int B)
{
    float final = 1.0f - factor * ((1.0f - (((float)(A) / 255.0f))) * ((1.0f - ((float)(B) / 255.0f))));
    return final;
}

bool backgroundColor(unsigned int color)
{
    if (color < (unsigned int)(127))
    {
        return true;
    }
    else
    {
        return false;
    }
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

        unsigned int redInt = (unsigned int)(scale(Apixels[i].redInt * Bpixels[i].redInt / 255.0f));
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        unsigned int greenInt = (unsigned int)(scale(Apixels[i].greenInt * Bpixels[i].greenInt / 255.0f));
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        unsigned int blueInt = (unsigned int)(scale(Apixels[i].blueInt * Bpixels[i].blueInt / 255.0f));
        unsigned char blue = A.ConvertItoC(blueInt);
        Cpixel.blue = blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}

Image Subtract(Image &A, Image &B)
{
    Image C;

    Image::Header header = A.getHeader();
    C.setHeader(header);
    A.setUnsignedInts();
    B.setUnsignedInts();

    vector<Pixel> Apixels = A.getPixelVector();
    vector<Pixel> Bpixels = B.getPixelVector();

    vector<Pixel> Cpixels;

    int final;
    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Cpixel;

        // Subtracts the red in each image from each other
        final = Apixels[i].redInt - Bpixels[i].redInt;
        // Clams the value found to check for over/underflow
        unsigned int redInt = clamp(final);
        // Converts the red integer to a char
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        final = Apixels[i].greenInt - Bpixels[i].greenInt;
        unsigned int greenInt = clamp(final);
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        final = Apixels[i].blueInt - Bpixels[i].blueInt;
        unsigned int blueInt = clamp(final);
        unsigned char blue = A.ConvertItoC(blueInt);
        Cpixel.blue = blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}

Image Screen(Image &A, Image &B)
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

        float redFloat = screenAlgo(1.0f, Apixels[i].redInt, Bpixels[i].redInt);
        unsigned int redInt = (unsigned int)scale(redFloat * 255.0f);
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        float greenFloat = screenAlgo(1.0f, Apixels[i].greenInt, Bpixels[i].greenInt);
        unsigned int greenInt = (unsigned int)scale(greenFloat * 255.0f);
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        float blueFloat = screenAlgo(1.0f, Apixels[i].blueInt, Bpixels[i].blueInt);
        unsigned int blueInt = (unsigned int)scale(blueFloat * 255.0f);
        unsigned char blue = A.ConvertItoC(blueInt);
        Cpixel.blue = blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}

Image Overlay(Image &A, Image &B)
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
        unsigned int redInt;
        unsigned int greenInt;
        unsigned int blueInt;

        if (backgroundColor(Apixels[i].redInt))
        {
            redInt = (unsigned int)(2.0f * scale(Apixels[i].redInt * Bpixels[i].redInt / 255.0f));
        }
        else
        {
            float redFloat = screenAlgo(2.0f, Apixels[i].redInt, Bpixels[i].redInt);
            redInt = (unsigned int)scale(redFloat * 255.0f);
        }
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        if (backgroundColor(Apixels[i].greenInt))
        {
            greenInt = (unsigned int)(2.0f * scale(Apixels[i].greenInt * Bpixels[i].greenInt / 255.0f));
        }
        else
        {
            float greenFloat = screenAlgo(2.0f, Apixels[i].greenInt, Bpixels[i].greenInt);
            greenInt = (unsigned int)scale(greenFloat * 255.0f);
        }
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        if (backgroundColor(Apixels[i].blueInt))
        {
            blueInt = (unsigned int)(2.0f * scale(Apixels[i].blueInt * Bpixels[i].blueInt / 255.0f));
        }
        else
        {
            float blueFloat = screenAlgo(2.0f, Apixels[i].blueInt, Bpixels[i].blueInt);
            blueInt = (unsigned int)scale(blueFloat * 255.0f);
        }
        unsigned char blue = A.ConvertItoC(blueInt);
        Cpixel.blue = blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}

Image addGreen(Image &A)
{
    Image C;
    vector<Pixel> Apixels = A.getPixelVector();

    Image::Header header = A.getHeader();
    C.setHeader(header);

    vector<Pixel> Cpixels;

    int final;
    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Cpixel;
        Cpixel.red = Apixels[i].red;
        Cpixel.blue = Apixels[i].blue;

        final = Apixels[i].greenInt + 200;
        unsigned int greenInt = clamp(final);
        unsigned char green = A.ConvertItoC(greenInt);
        Cpixel.green = green;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}

Image scaleRed(Image &A)
{
    Image C;
    Image::Header header = A.getHeader();
    C.setHeader(header);

    vector<Pixel> Apixels = A.getPixelVector();
    vector<Pixel> Cpixels;

    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Cpixel;

        unsigned int redInt;
        float redFloat = ((float)Apixels[i].redInt / 255.0f) * 4.0f;
        redInt = (unsigned int)scale(redFloat * 255.0f);
        redInt = clamp(redInt);
        unsigned char red = A.ConvertItoC(redInt);
        Cpixel.red = red;

        Cpixel.green = Apixels[i].green;

        Cpixel.blue = 0;
        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);
    C.setUnsignedInts();

    return C;
}

Image splitChannels(string rgb, Image &A)
{
    Image C;
    Image::Header header = A.getHeader();
    C.setHeader(header);

    vector<Pixel> Apixels = A.getPixelVector();
    vector<Pixel> Cpixels;

    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Cpixel;
        unsigned char channel;

        if (rgb == "red")
        {
            channel = Apixels[i].red;
        }
        else if (rgb == "green")
        {
            channel = Apixels[i].green;
        }
        else if (rgb == "blue")
        {
            channel = Apixels[i].blue;
        }

        Cpixel.red = channel;
        Cpixel.green = channel;
        Cpixel.blue = channel;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);
    C.setUnsignedInts();

    return C;
}

Image Combine(Image &A, Image &B, Image &C)
{
    Image D;
    Image::Header header = A.getHeader();
    D.setHeader(header);

    vector<Pixel> Apixels = A.getPixelVector();
    vector<Pixel> Bpixels = B.getPixelVector();
    vector<Pixel> Cpixels = C.getPixelVector();

    vector<Pixel> Dpixels;

    for (unsigned int i = 0; i < Apixels.size(); i++)
    {
        Pixel Dpixel;

        Dpixel.red = Apixels[i].red;
        Dpixel.green = Bpixels[i].green;
        Dpixel.blue = Cpixels[i].blue;

        Dpixels.push_back(Dpixel);
    }
    D.setPixelVector(Dpixels);

    return D;
}

Image Rotate(Image &A)
{
    Image C;

    Image::Header header = A.getHeader();
    C.setHeader(header);

    vector<Pixel> Apixels = A.getPixelVector();

    vector<Pixel> Cpixels;

    for (unsigned int i = Apixels.size(); i > 0; i--)
    {
        Pixel Cpixel;

        Cpixel.red = Apixels[i].red;
        Cpixel.green = Apixels[i].green;
        Cpixel.blue = Apixels[i].blue;

        Cpixels.push_back(Cpixel);
    }
    C.setPixelVector(Cpixels);

    return C;
}