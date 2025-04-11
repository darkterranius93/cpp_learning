// Герберт Шилдт: С++ базовый курс
// Передача функции структуры в качестве аргумента
// структура передается по значению
// Created by Денис Скрипниченко on 11.04.2025.
//
#include <iostream>

// Определяем тип структуры
struct sample {
    int a;
    char ch;
};

void f1(sample parm);

int main() {
    struct sample arg; // Объявляем переменную arg типа sample
    arg.a = 1000;
    arg.ch = 'x';

    f1(arg);

    return 0;
}

void f1(sample parm) {
    std::cout << parm.a << " " << parm.ch << std::endl;
}