// Герберт Шилдт: С++ базовый курс
// Пример использования модификатора extern
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>

int main() {
    extern int first, last; // Использование глобальных переменных
    std::cout << first << " " << last << std::endl;
    return 0;
}

int first = 10, last = 20;