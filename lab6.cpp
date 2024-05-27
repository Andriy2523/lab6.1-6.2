#include <iostream>
#include "graphics.h"
#include<Windows.h>

void displayMenu() {
    std::cout << "1. �������� ��������\n";
    std::cout << "2. ���������� ��������\n";
    std::cout << "3. ������ ����� ��������\n";
    std::cout << "4. ������ ���� ��������\n";
    std::cout << "5. ��������� ��������\n";
    std::cout << "6. �������� ��������\n";
    std::cout << "7. �����\n";
    std::cout << "������ �����: ";
}

int main() {
    SetConsoleOutputCP(1251);
    Trapezoid trapezoid;
    bool isCreated = false;
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1: {
            double x, y, topBase, bottomBase, height;
            std::string color;
            std::cout << "������ x, y, ������ ������, ����� ������, ������, ����: ";
            std::cin >> x >> y >> topBase >> bottomBase >> height >> color;
            trapezoid = Trapezoid(x, y, topBase, bottomBase, height, color);
            isCreated = true;
            break;
        }
        case 2: {
            if (!isCreated) {
                std::cout << "�������� �� �� ��������.\n";
                break;
            }
            double dx, dy;
            std::cout << "������ dx, dy: ";
            std::cin >> dx >> dy;
            trapezoid.move(dx, dy);
            break;
        }
        case 3: {
            if (!isCreated) {
                std::cout << "�������� �� �� ��������.\n";
                break;
            }
            double factor;
            std::cout << "������ ���������� ���� ������: ";
            std::cin >> factor;
            trapezoid.resize(factor);
            break;
        }
        case 4: {
            if (!isCreated) {
                std::cout << "�������� �� �� ��������.\n";
                break;
            }
            std::string color;
            std::cout << "������ ����� ����: ";
            std::cin >> color;
            trapezoid.changeColor(color);
            break;
        }
        case 5: {
            if (!isCreated) {
                std::cout << "�������� �� �� ��������.\n";
                break;
            }
            double angle;
            std::cout << "������ ��� ��������: ";
            std::cin >> angle;
            trapezoid.rotate(angle);
            break;
        }
        case 6: {
            if (!isCreated) {
                std::cout << "�������� �� �� ��������.\n";
                break;
            }
            trapezoid.display();
            break;
        }
        case 7: {
            return 0;
        }
        default: {
            std::cout << "������ �����. ��������� �� ���.\n";
            break;
        }
        }
    }
}
