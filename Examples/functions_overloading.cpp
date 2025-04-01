// Герберт Шилдт: С++ базовый курс
// "Трехкратная" перегрузка функции f().
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>

void f(int i); // один целочисленный параметр
void f(int i, int j); // два целочисленных параметра
void f(double k); // один параметр типа double

int main() {
    f(10); // вызов функции f(int)
    f(10, 20); // вызов функции f(int, int)
    f(12.23); // вызов функции f(double)

    return 0;
}

void f(int i) {
    std::cout << "В функции f(int), i равно " << i << std::endl;
}

void f(int i, int j) {
    std::cout << "В функции f(int, int), i равно " << i << ", j равно " << j << std::endl;
}

void f(double k) {
    std::cout << "В функции f(double), k равно " << k << std::endl;
}