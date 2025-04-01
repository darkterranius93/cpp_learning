// Герберт Шилдт: С++ базовый курс
// Пример использования static-переменной:
// вычисляем текущее среднее значение от чисел, вводимых пользователем.
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>

int r_avg(int i);

int main() {
    int num;
    do {
        std::cout << "Введите числа (-1 означает выход): ";
        std::cin >> num;
        if (num != -1) {
            std::cout << "Текущее среднее равно: " << r_avg(num);
            std::cout << std::endl;
        }
    } while (num > -1);
    return 0;
}

// Вычисляем текущее среднее
int r_avg(int i) {
    static int sum = 0, count = 0;
    sum = sum + i;
    count++;
    return sum / count;
}