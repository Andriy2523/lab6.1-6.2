#include <iostream>
#include "graphics.h"
#include<Windows.h>

void displayMenu() {
    std::cout << "1. Створити трапецію\n";
    std::cout << "2. Перемістити трапецію\n";
    std::cout << "3. Змінити розмір трапеції\n";
    std::cout << "4. Змінити колір трапеції\n";
    std::cout << "5. Повернути трапецію\n";
    std::cout << "6. Показати трапецію\n";
    std::cout << "7. Вийти\n";
    std::cout << "Оберіть опцію: ";
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
            std::cout << "Введіть x, y, верхню основу, нижню основу, висоту, колір: ";
            std::cin >> x >> y >> topBase >> bottomBase >> height >> color;
            trapezoid = Trapezoid(x, y, topBase, bottomBase, height, color);
            isCreated = true;
            break;
        }
        case 2: {
            if (!isCreated) {
                std::cout << "Трапецію ще не створено.\n";
                break;
            }
            double dx, dy;
            std::cout << "Введіть dx, dy: ";
            std::cin >> dx >> dy;
            trapezoid.move(dx, dy);
            break;
        }
        case 3: {
            if (!isCreated) {
                std::cout << "Трапецію ще не створено.\n";
                break;
            }
            double factor;
            std::cout << "Введіть коефіцієнт зміни розміру: ";
            std::cin >> factor;
            trapezoid.resize(factor);
            break;
        }
        case 4: {
            if (!isCreated) {
                std::cout << "Трапецію ще не створено.\n";
                break;
            }
            std::string color;
            std::cout << "Введіть новий колір: ";
            std::cin >> color;
            trapezoid.changeColor(color);
            break;
        }
        case 5: {
            if (!isCreated) {
                std::cout << "Трапецію ще не створено.\n";
                break;
            }
            double angle;
            std::cout << "Введіть кут повороту: ";
            std::cin >> angle;
            trapezoid.rotate(angle);
            break;
        }
        case 6: {
            if (!isCreated) {
                std::cout << "Трапецію ще не створено.\n";
                break;
            }
            trapezoid.display();
            break;
        }
        case 7: {
            return 0;
        }
        default: {
            std::cout << "Невірна опція. Спробуйте ще раз.\n";
            break;
        }
        }
    }
}
