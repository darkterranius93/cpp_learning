// Герберт Шилдт: С++ базовый курс
// Инициализация массива объектов
// Created by Денис Скрипниченко on 18.04.2025.
//
#include <iostream>

class samp {
    int a;

    public:
    samp(int n) { a = n;}
    int get_a() { return a; }
};

int main() {
    // samp sampArray[4] = { samp(-1), samp(-2), samp(-3), samp(-4) };
    samp sampArray[4] = { -1, -2, -3, -4 };
    int i;

    for (i = 0; i < 4; i++) {
        std::cout << sampArray[i].get_a() << " ";
    }
    std::cout << std::endl;

    return 0;
}