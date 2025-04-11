// Герберт Шилдт: С++ базовый курс
// Демонстрация присваивания значений структур
// Created by Денис Скрипниченко on 11.04.2025.
//
#include <iostream>

struct stype {
    int a, b;
};

int main() {
    stype svar1, svar2;

    svar1.a = svar1.b = 10;
    svar2.a = svar2.b = 20;

    std::cout << "Стуктуры до присваивания." << std::endl;
    std::cout << "svar1: " << svar1.a << " " << svar1.b << std::endl;
    std::cout << "svar2: " << svar2.a << " " << svar2.b << std::endl;
    std::cout << std::endl;

    svar2 = svar1;
    std::cout << "Стуктуры после присваивания." << std::endl;
    std::cout << "svar1: " << svar1.a << " " << svar1.b << std::endl;
    std::cout << "svar2: " << svar2.a << " " << svar2.b;

    return 0;
}