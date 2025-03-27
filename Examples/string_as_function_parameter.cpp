// Герберт Шилдт: С++ базовый курс
// Передача функции строки
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>
#include <cstring>
#include <cctype>

void stringtoupper(char *str);

int main() {
    char str[80];

    strcpy(str, "I like C++");
    stringtoupper(str);

    std::cout << str << std::endl; // Отображаем строку с использованием прописного написания символов

    return 0;
}

void stringtoupper(char *str) {
    while(*str) {
        *str = toupper(*str); // Получаем прописной эквивалент одного символа
        str++;
    }
}