#include <string>
#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

// Base Class
class Shape
{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape() {}
};

// Derived and Base Class
class Shape2D : virtual public Shape
{
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;

    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;

    virtual ~Shape2D() {}
};

// Derived and Base Class
class Shape3D : virtual public Shape
{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;

    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;

    virtual ~Shape3D() {}
};

// Derived Class
class Square : public Shape2D
{
public:
    Square();
    Square(float sideLength);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~Square() {}

private:
    float side;
};

// Derived Class
class Triangle : public Shape2D
{
public:
    Triangle();
    Triangle(float b, float h);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~Triangle() {}

private:
    float base;
    float height;
};

// Derived Class
class Circle : public Shape2D
{
public:
    Circle();
    Circle(float r);
    float Area() const;
    string GetName2D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~Circle() {}

private:
    float radius;
};

// Derived Class
class TriangularPyramid : public Shape3D, private Triangle
{
public:
    TriangularPyramid();
    TriangularPyramid(float h, float baseLength, float baseHeight);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~TriangularPyramid() {}

private:
    float height;
};

// Derived Class
class Cylinder : public Shape3D, private Circle
{
public:
    Cylinder();
    Cylinder(float h, float radius);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~Cylinder() {}

private:
    float height;
};

// Derived Class
class Sphere : public Shape3D, private Circle
{
public:
    Sphere();
    Sphere(float r);
    float Volume() const;
    string GetName3D() const;
    void Scale(float scaleFactor);
    void Display() const;

    ~Sphere() {}

private:
    float radius;
};