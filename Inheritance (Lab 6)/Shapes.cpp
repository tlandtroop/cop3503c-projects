#include "Shapes.h"
#include <iostream>
#include <string>
using namespace std;
const float PI = 3.14159f;

// Displays the area of the 2D shape
void Shape2D::ShowArea() const
{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

// Overloading the > operator
bool Shape2D::operator>(const Shape2D &rhs) const
{
    return this->Area() > rhs.Area();
}

// Overloading the < operator
bool Shape2D::operator<(const Shape2D &rhs) const
{
    return this->Area() < rhs.Area();
}

// Overloading the == operator
bool Shape2D::operator==(const Shape2D &rhs) const
{
    return this->Area() == rhs.Area();
}

// Displays the volume of the 3D shape
void Shape3D::ShowVolume() const
{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

// Overloading the > operator
bool Shape3D::operator>(const Shape3D &rhs) const
{
    return this->Volume() > rhs.Volume();
}

// Overloading the < operator
bool Shape3D::operator<(const Shape3D &rhs) const
{
    return this->Volume() < rhs.Volume();
}

// Overloading the == operator
bool Shape3D::operator==(const Shape3D &rhs) const
{
    return this->Volume() == rhs.Volume();
}

// Square Class Definitions
Square::Square()
{
    side = 0;
}

Square::Square(float sideLength)
{
    this->side = sideLength;
}

float Square::Area() const
{
    return side * side;
}

string Square::GetName2D() const
{
    return "Square";
}

void Square::Scale(float scaleFactor)
{
    side *= scaleFactor;
}

void Square::Display() const
{
    Shape2D::ShowArea();
    cout << "Length of a side: " << side << endl;
}

// Triangle Class Definitions
Triangle::Triangle()
{
    base = 0;
    height = 0;
}

Triangle::Triangle(float b, float h)
{
    this->base = b;
    this->height = h;
}

float Triangle::Area() const
{
    return 0.5 * base * height;
}

string Triangle::GetName2D() const
{
    return "Triangle";
}

void Triangle::Scale(float scaleFactor)
{
    base *= scaleFactor;
    height *= scaleFactor;
}

void Triangle::Display() const
{
    Shape2D::ShowArea();
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

// Circle Class Definitions
Circle::Circle()
{
    radius = 0;
}

Circle::Circle(float r)
{
    this->radius = r;
}

float Circle::Area() const
{
    return PI * pow(radius, 2.0);
}

string Circle::GetName2D() const
{
    return "Circle";
}

void Circle::Scale(float scaleFactor)
{
    radius *= scaleFactor;
}

void Circle::Display() const
{
    Shape2D::ShowArea();
    cout << "Radius: " << radius << endl;
}

// Triangular Pyramid Class Definitions
TriangularPyramid::TriangularPyramid() : Triangle()
{
    height = 0;
    Triangle();
}

TriangularPyramid::TriangularPyramid(float h, float baseLength, float baseHeight) : Triangle(baseLength, baseHeight)
{
    height = h;
}

float TriangularPyramid::Volume() const
{
    float volume = Triangle::Area() * height / 3;
    return volume;
}

string TriangularPyramid::GetName3D() const
{
    string name = "TriangularPyramid";
    return name;
}

void TriangularPyramid::Scale(float scaleFactor)
{
    Triangle::Scale(scaleFactor);
    height *= scaleFactor;
}

void TriangularPyramid::Display() const
{
    Shape3D::ShowVolume();
    cout << "The height is: " << height << endl;
    Triangle::Display();
}

// Cylinder Class Definitions
Cylinder::Cylinder()
{
    height = 0;
}

Cylinder::Cylinder(float h, float radius) : Circle(radius)
{
    height = h;
}

float Cylinder::Volume() const
{
    float volume = Circle::Area() * height;
    return volume;
}

string Cylinder::GetName3D() const
{
    string name = "Cylinder";
    return name;
}

void Cylinder::Scale(float scaleFactor)
{
    Circle::Scale(scaleFactor);
    height *= scaleFactor;
}

void Cylinder::Display() const
{
    Shape3D::ShowVolume();
    cout << "The height is: " << height << endl;
    Circle::Display();
}

// Sphere Class Definitions
Sphere::Sphere()
{
    radius = 0;
}

Sphere::Sphere(float r) : Circle(r)
{
    radius = r;
}

float Sphere::Volume() const
{
    float volume = 4 * PI * pow(radius, 3) / 3;
    return volume;
}

string Sphere::GetName3D() const
{
    string name = "Sphere";
    return name;
}

void Sphere::Scale(float scaleFactor)
{
    radius *= scaleFactor;
}

void Sphere::Display() const
{
    Shape3D::ShowVolume();
    Circle::Display();
}