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

    // Part 2: Subtract the two images
    cout << "Part 2 is starting..." << endl;
    Image partTwo = Subtract(car, layer2);
    partTwo.WriteImage("output/part2.tga");
    passedTests += testImages(partTwo, EXAMPLE_part2);

    // Part 3: Multiply and Blending Modes
    cout << "Part 3 is starting..." << endl;
    Image temp = Multiply(layer1, pattern2);
    Image partThree = Screen(text, temp);
    partThree.WriteImage("output/part3.tga");
    passedTests += testImages(partThree, EXAMPLE_part3);

    // Part 4: Multiply then subtract
    cout << "Part 4 is starting..." << endl;
    Image temp2 = Multiply(layer2, circles);
    Image partFour = Subtract(temp2, pattern2);
    partFour.WriteImage("output/part4.tga");
    passedTests += testImages(partFour, EXAMPLE_part4);

    // Part 5: Overlay images
    cout << "Part 5 is starting..." << endl;
    Image partFive = Overlay(pattern1, layer1);
    partFive.WriteImage("output/part5.tga");
    passedTests += testImages(partFive, EXAMPLE_part5);

    // Part 6: Add 200 to green in car.tga
    cout << "Part 6 is starting..." << endl;
    Image partSix = addGreen(car);
    partSix.WriteImage("output/part6.tga");
    passedTests += testImages(partSix, EXAMPLE_part6);

    // Part 7: Scale red by 4 and blue by 0 in car.tga
    cout << "Part 7 is starting..." << endl;
    Image partSeven = scaleRed(car);
    partSeven.WriteImage("output/part7.tga");
    passedTests += testImages(partSeven, EXAMPLE_part7);

    // Part 8: Break an image into three separate channels
    cout << "Part 8 is starting..." << endl;
    Image partEight_red = splitChannels("red", car);
    partEight_red.WriteImage("output/part8_r.tga");
    passedTests += testImages(partEight_red, EXAMPLE_part8_r);
    Image partEight_green = splitChannels("green", car);
    partEight_green.WriteImage("output/part8_g.tga");
    passedTests += testImages(partEight_green, EXAMPLE_part8_g);
    Image partEight_blue = splitChannels("blue", car);
    partEight_blue.WriteImage("output/part8_b.tga");
    passedTests += testImages(partEight_blue, EXAMPLE_part8_b);

    // Part 9: Combine three channels into one image
    cout << "Part 9 is starting..." << endl;
    Image partNine = Combine(layer_red, layer_green, layer_blue);
    partNine.WriteImage("output/part9.tga");
    passedTests += testImages(partNine, EXAMPLE_part9);

    // Part 10: Rotate 180deg
    cout << "Part 10 is starting..." << endl;
    Image partTen = Rotate(text2);
    partTen.WriteImage("output/part10.tga");
    passedTests += testImages(partTen, EXAMPLE_part10);

    cout << "Total tests passed: " << passedTests << "/" << totalTests << endl;

    return 0;
}
