// Герберт Шилдт: С++ базовый курс
// Одна из версий функции strlen().
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>
#include <cstring>
#include <cctype>

int mystrlen(char *str);

int main() {
    std::cout << "Длина строки `Hello everyone` равна: " << std::endl;
    std::cout << mystrlen("Hello everyone") << std::endl;
    return 0;
}

/**
* Нестандартная реализация функции strlen().
* @param str Указатель на строку
* @return Длина строки
*/
int mystrlen(char *str) {
    int i;
    for (i = 0; str[i]; i++); // Находим конец строки
    return i;
}