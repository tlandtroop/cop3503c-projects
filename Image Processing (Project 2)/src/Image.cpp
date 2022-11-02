#include "Image.h"
#include <fstream>
using namespace std;

void Image::LoadImage(string name)
{

    // Opens the file
    ifstream File(name, ios_base::binary);

    // Read the header
    File.read(&header.idLength, sizeof(header.idLength));
    File.read(&header.colorMapType, sizeof(header.colorMapType));
    File.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
    File.read((char *)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    File.read((char *)&header.colorMapLength, sizeof(header.colorMapLength));
    File.read(&header.colorMapDepth, sizeof(header.colorMapDepth));

    // Read the specifications of the image file
    File.read((char *)&header.xOrigin, sizeof(header.xOrigin));
    File.read((char *)&header.yOrigin, sizeof(header.yOrigin));
    File.read((char *)&header.width, sizeof(header.width));
    File.read((char *)&header.height, sizeof(header.height));
    File.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    File.read(&header.imageDescriptor, sizeof(header.imageDescriptor));

    // Read and add pixels to the pixel vector
    unsigned int totalPixels = header.height * header.width;
    for (unsigned int i = 0; i < totalPixels; i++)
    {
        Pixel pixel;
        File.read((char *)&pixel.blue, sizeof(pixel.blue));
        File.read((char *)&pixel.green, sizeof(pixel.green));
        File.read((char *)&pixel.red, sizeof(pixel.red));

        pixel.blueInt = ConvertCtoI(pixel.blue);
        pixel.greenInt = ConvertCtoI(pixel.green);
        pixel.redInt = ConvertCtoI(pixel.red);

        pixels.push_back(pixel);
    }

    // Close the image file when finished
    File.close();
}

void Image::WriteImage(string outName)
{
    fstream File(outName, ios_base::binary | ios_base::out);

    // Write the header
    File.write(&header.idLength, sizeof(header.idLength));
    File.write(&header.colorMapType, sizeof(header.colorMapType));
    File.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
    File.write((char *)&header.colorMapOrigin, sizeof(header.colorMapOrigin));
    File.write((char *)&header.colorMapLength, sizeof(header.colorMapLength));
    File.write(&header.colorMapDepth, sizeof(header.colorMapDepth));

    // Write the specifications of the image file
    File.write((char *)&header.xOrigin, sizeof(header.xOrigin));
    File.write((char *)&header.yOrigin, sizeof(header.yOrigin));
    File.write((char *)&header.width, sizeof(header.width));
    File.write((char *)&header.height, sizeof(header.height));
    File.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
    File.write(&header.imageDescriptor, sizeof(header.imageDescriptor));

    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        Pixel pixel = pixels.at(i);
        File.write((char *)&pixel.blue, 1);
        File.write((char *)&pixel.green, 1);
        File.write((char *)&pixel.red, 1);
    }

    File.close();
}

unsigned int Image::ConvertCtoI(unsigned char character)
{
    // Converts unsigned char to unsigned int by removing null terminator and type casting
    return (unsigned int)(character - '\0');
}

unsigned char Image::ConvertItoC(unsigned int integer)
{
    // Converts unsigned int to unsigned char by adding null terminator and type casting
    return (unsigned char)(integer + '\0');
}

void Image::setUnsignedInts()
{
    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        pixels[i].redInt = ConvertCtoI(pixels[i].red);
        pixels[i].greenInt = ConvertCtoI(pixels[i].green);
        pixels[i].blueInt = ConvertCtoI(pixels[i].blue);
    }
}

Image::Header Image::getHeader()
{
    return header;
}

void Image::setHeader(Header &headerData)
{
    header.idLength = headerData.idLength;
    header.colorMapType = headerData.colorMapType;
    header.dataTypeCode = headerData.dataTypeCode;
    header.colorMapOrigin = headerData.colorMapOrigin;
    header.colorMapLength = headerData.colorMapLength;
    header.colorMapDepth = headerData.colorMapDepth;
    header.xOrigin = headerData.xOrigin;
    header.yOrigin = headerData.yOrigin;
    header.width = headerData.width;
    header.height = headerData.height;
    header.bitsPerPixel = headerData.bitsPerPixel;
    header.imageDescriptor = headerData.imageDescriptor;
}

vector<Pixel> Image::getPixelVector()
{
    return pixels;
}

void Image::setPixelVector(vector<Pixel> &vector)
{
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        pixels.push_back(vector[i]);
    }
}

bool Image::operator==(Image &other)
{
    for (unsigned int i = 0; i < pixels.size(); i++)
    {
        if ((pixels[i].red == other.pixels[i].red) && (pixels[i].green == other.pixels[i].green) && (pixels[i].blue == other.pixels[i].blue))
        {
            return true;
        }
    }
    return false;
}