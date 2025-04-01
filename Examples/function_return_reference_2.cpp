// Герберт Шилдт: С++ базовый курс
// Возврат ссылки
// Created by Денис Скрипниченко on 31.03.2025.
//
#include <iostream>


double &change_it(int i); // Функция возвращает ссылку
double vals[] = {1.1, 2.2, 3.3, 4.4, 5.5};

int main() {
    int i;
    std::cout << "Вот исходные значения: ";
    for (i = 0; i < 5; i++) {
        std::cout << vals[i] << ' ';
    }
    std::cout << std::endl;

    change_it(1) = 5298.23; // Изменяем 2-й элемент
    change_it(3) = -98.8; // Изменяем 4-й элемент

    std::cout << "Вот измененные значения: ";
    for (i = 0; i < 5; i++) {
        std::cout << vals[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

double &change_it(int i) {
    return vals[i];
}