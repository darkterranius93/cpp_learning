// Герберт Шилдт: С++ базовый курс
// Пример использование спецификатора const
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>

void code(const char *str);
void f(const int &i);

int main() {
    code("This is test.");

    int k = 10;
    f(k);
    return 0;
}

/* Использование спецификатора const гарантирует, что str
не может изменить аргумент, на который он указывает. */
void code(const char *str) {
    while(*str) {
        // *str = *str + 1; // Ошибка, аргумент модифицировать нельзя
        std::cout << (char) (*str+1) << std::endl;
        str++;
    }
}

// Использование ссылочного const-параметра
void f(const int &i) {
    // i = 100; // Ошибка, нельзя модифицировать const-ссылку
    std::cout << i << std::endl;
}