// Герберт Шилдт: С++ базовый курс
// Исправление некорректной программы
// Created by Денис Скрипниченко on 25.03.2025.
//
#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char s[80];
    char *p1;
    // p1 = s; // Было

    do {
        p1 = s; // Стало
        std::cout << "Заведите строку: ";
        gets(p1); // Считывает строку

        // Выводим ASCII-значения каждого символа
        while(*p1) {
            std::cout << (int) *p1++ << ' ' << std::endl;
        }
    } while(strcmp(s, "конец"));

    return 0;
}