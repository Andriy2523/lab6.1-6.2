#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <cmath>
#include <string>

class Point {
protected:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~Point() {}
    virtual void move(double dx, double dy) {
        x += dx;
        y += dy;
    }
    virtual void display() const {
        std::cout << "����� (" << x << ", " << y << ")\n";
    }
};

class Shape : public Point {
protected:
    double size;
    std::string color;
public:
    Shape(double x = 0, double y = 0, double size = 1.0, std::string color = "������")
        : Point(x, y), size(size), color(color) {}
    virtual ~Shape() {}
    virtual void resize(double factor) {
        size *= factor;
    }
    virtual void changeColor(const std::string& newColor) {
        color = newColor;
    }
    virtual void rotate(double angle) = 0; // ����� ��������� �������
    virtual void display() const override = 0; // ����� ��������� �������
};

class Trapezoid : public Shape {
private:
    double topBase, bottomBase, height;
    double angle; // ��� ���������
public:
    Trapezoid(double x = 0, double y = 0, double topBase = 1.0, double bottomBase = 2.0, double height = 1.0, std::string color = "������")
        : Shape(x, y, 1.0, color), topBase(topBase), bottomBase(bottomBase), height(height), angle(0) {}
    void rotate(double angle) override {
        this->angle += angle;
    }
    void display() const override {
        std::cout << "�������� � ������� � ����� (" << x << ", " << y << ") � �������� ������� " << topBase
            << ", ������� ������� " << bottomBase << ", ������� " << height << ", �������� " << color
            << " � ��������� �� " << angle << " �������.\n";
    }
};

#endif // GRAPHICS_H
