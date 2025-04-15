// Герберт Шилдт: С++ базовый курс
// Пример использование унарного оператора НЕ посредством отображения
// некоторого числа и его дополнения до 1 в двоичном коде
// Created by Денис Скрипниченко on 03.04.2025.
//
#import <iostream>
#import "disp_binary.cpp"

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
