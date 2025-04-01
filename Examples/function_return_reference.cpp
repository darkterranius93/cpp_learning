// Герберт Шилдт: С++ базовый курс
// Возврат ссылки
// Created by Денис Скрипниченко on 31.03.2025.
//
#include <iostream>

double &f();
double val = 100.0;

int main() {
    double newval;
    std::cout << f() << std::endl; // Отображаем значение val

    newval = f(); // Присваиваем значение val переменной newval
    std::cout << newval << std::endl; // Отображаем значение newval

    f() = 99.1; // Изменяем значение val
    std::cout << f() << std::endl; // Отображаем новое значение val

    return 0;
}

double &f() {
  return val; // Возвращаем ссылку на val
}