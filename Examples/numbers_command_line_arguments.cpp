// Герберт Шилдт: С++ базовый курс
// Эта программа отображает сумму двух числовых аргументов командной строки
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    double a, b;

    if (argc != 3) {
        std::cout << "Использование: add число число" << std::endl;
        return 1;
    }

    // Функция atof() преобразует строку str в величину типа double
    a = atof(argv[1]);
    b = atof(argv[2]);

    std::cout << a + b << std::endl;
    return 0;
}