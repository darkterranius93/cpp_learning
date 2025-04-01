// Герберт Шилдт: С++ базовый курс
// Эта программа демонстрирует влияние, которое может оказать
// использование register-переменной на скорость выполнения программы
// Created by Денис Скрипниченко on 01.04.2025.
//
#include <iostream>
#include <ctime>

unsigned int i; // не register-переменная
unsigned int delay;

int main() {
    register unsigned int j;
    long start, end;

    start = clock();
    for (delay = 0; delay < 50; delay++) {
        for (i = 0; i < 64000000; i++) {
            end = clock();
        }
    }
    std::cout << "Количество тиков для не register-цикла: ";
    std::cout << end - start << std::endl;

    start = clock();
    for (delay = 0; delay < 50; delay++) {
        for (j = 0; j < 64000000; j++) {
            end = clock();
        }
    }
    std::cout << "Количество тиков для register-цикла: ";
    std::cout << end - start << std::endl;

    return 0;
}
