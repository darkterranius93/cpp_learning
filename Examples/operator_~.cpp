// Герберт Шилдт: С++ базовый курс
// Пример использование унарного оператора НЕ посредством отображения
// некоторого числа и его дополнения до 1 в двоичном коде
// Created by Денис Скрипниченко on 03.04.2025.
//
#import <iostream>

void disp_binary(unsigned u);

int main() {
    unsigned u;
    std::cout << "Введите число между 0 и 255:";
    std::cin >> u;

    std::cout << "Исходное число в двоичном коде: ";
    disp_binary(u);
    std::cout << std::endl;

    std::cout << "Его дополнение до единицы: ";
    disp_binary(~u);
    return 0;
}

void disp_binary(unsigned u) {
    int t;
    for (t = 128; t > 0; t = t/2) {
        if (u & t) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}