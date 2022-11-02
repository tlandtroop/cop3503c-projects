#include <iostream>
#include <vector>
#include <string>
#include "Image.h"
#include "Functions.h"

int testImages(Image &img1, Image &img2)
{
    if (img1 == img2)
    {
        cout << "Images match. Test has passed." << endl;
        return 1;
    }
    else
    {
        cout << "Images do not match. Test has failed." << endl;
        return 0;
    }
}

int main()
{
    int passedTests = 0;
    double totalTests = 12;

    // Load the files
    Image layer1;
    Image layer2;
    Image pattern1;
    Image pattern2;
    Image text;
    Image text2;
    Image car;
    Image circles;
    Image layer_blue;
    Image layer_green;
    Image layer_red;

    layer1.LoadImage("./input/layer1.tga");
    layer2.LoadImage("./input/layer2.tga");
    pattern1.LoadImage("./input/pattern1.tga");
    pattern2.LoadImage("./input/pattern2.tga");
    text.LoadImage("./input/text.tga");
    text2.LoadImage("./input/text2.tga");
    car.LoadImage("./input/car.tga");
    circles.LoadImage("./input/circles.tga");
    layer_blue.LoadImage("./input/layer_blue.tga");
    layer_green.LoadImage("./input/layer_green.tga");
    layer_red.LoadImage("./input/layer_red.tga");

    // Load the example files for testing
    Image EXAMPLE_part1;
    Image EXAMPLE_part2;
    Image EXAMPLE_part3;
    Image EXAMPLE_part4;
    Image EXAMPLE_part5;
    Image EXAMPLE_part6;
    Image EXAMPLE_part7;
    Image EXAMPLE_part8_r;
    Image EXAMPLE_part8_g;
    Image EXAMPLE_part8_b;
    Image EXAMPLE_part9;
    Image EXAMPLE_part10;

    EXAMPLE_part1.LoadImage("./examples/EXAMPLE_part1.tga");
    EXAMPLE_part2.LoadImage("./examples/EXAMPLE_part2.tga");
    EXAMPLE_part3.LoadImage("./examples/EXAMPLE_part3.tga");
    EXAMPLE_part4.LoadImage("./examples/EXAMPLE_part4.tga");
    EXAMPLE_part5.LoadImage("./examples/EXAMPLE_part5.tga");
    EXAMPLE_part6.LoadImage("./examples/EXAMPLE_part6.tga");
    EXAMPLE_part7.LoadImage("./examples/EXAMPLE_part7.tga");
    EXAMPLE_part8_r.LoadImage("./examples/EXAMPLE_part8_r.tga");
    EXAMPLE_part8_g.LoadImage("./examples/EXAMPLE_part8_g.tga");
    EXAMPLE_part8_b.LoadImage("./examples/EXAMPLE_part8_b.tga");
    EXAMPLE_part9.LoadImage("./examples/EXAMPLE_part9.tga");
    EXAMPLE_part10.LoadImage("./examples/EXAMPLE_part10.tga");

    // Part 1: Multiply the two images together
    cout << "Part 1 is starting..." << endl;
    Image partOne = Multiply(layer1, pattern1);
    partOne.WriteImage("output/part1.tga");
    passedTests += testImages(partOne, EXAMPLE_part1);

    cout << "Total tests passed: " << passedTests << "/" << totalTests << endl;
    return 0;
}
