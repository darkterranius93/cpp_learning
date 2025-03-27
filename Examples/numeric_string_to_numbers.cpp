// Герберт Шилдт: С++ базовый курс
// Демонстрирование использования функций atoi(), atol() и atof().
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    int i;
    long j;
    double k;

    i = atoi("100");
    j = atol("100000");
    k = atof("-0.123");
    std::cout << i << " " << j << " " << k << std::endl;

    return 0;
}