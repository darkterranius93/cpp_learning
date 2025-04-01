// Герберт Шилдт: С++ базовый курс
// Пример использование 'enum'
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>

enum apple { Jonathan, Golden_Del, Red_Del, Winesap, Cortland, McIntosh };

// Массив строк, связанных с перечислением apple
char name[][20] = {
    "Jonathan",
    "Golden_Del",
    "Red_Del",
    "Winesap",
    "Cortland",
    "McIntosh"
};

int main() {
    apple fruit;
    // enum apple fruit;

    fruit = Jonathan;
    std::cout << name[fruit] << std::endl;

    fruit = Winesap;
    std::cout << name[fruit] << std::endl;

    fruit = McIntosh;
    std::cout << name[fruit] << std::endl;

    return 0;
}