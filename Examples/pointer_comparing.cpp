// Герберт Шилдт: С++ базовый курс
// Пример сравнения указателей
// Created by Денис Скрипниченко on 24.03.2025.
#include <iostream>
#include <cstdio>

int main() {
    int num[10];
    int *start, *end;
    start = num;
    end = &num[9];

    while (start <= end) {
        std::cout << "Введите число: ";
        std::cin >> *start;
        start++;
    }
    start = num; // Восстановление исходного значения указателя
    while (start <= end) {
        std::cout << *start << ' ';
        start++;
    }
    return 0;
}
