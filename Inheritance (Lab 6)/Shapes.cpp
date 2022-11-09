#include "Shapes.h"
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

float Square::Area()
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

float Triangle::Area()
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

float Circle::Area()
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

TriangularPyramid::TriangularPyramid(float h, float baseLength, float baseHeight) : Triangle(float baseLength, float baseHeight)
{
    height = h;
}

string TriangularPyramid::GetName3D() const
{
    string name = "TriangularPyramid";
    return name;
}

// Cylinder Class Definitions

// Sphere Class Definitions
