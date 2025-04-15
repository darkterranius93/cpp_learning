// Герберт Шилдт: С++ базовый курс
// Использование объединения для перестановки двух байтов
// в рамках короткого целочисленного значения
// Created by Денис Скрипниченко on 15.04.2025.
//
#include <iostream>
#include "disp_binary.cpp"

union swap_bytes {
    short int num;
    char bytes[2];
};

int main() {
    swap_bytes sb;
    char temp;
    sb.num = 15; // двоичный код: 0000 0000 0000 1111

    std::cout << "Исходные байты: ";
    disp_binary(sb.bytes[1]);
    std::cout << " ";
    disp_binary(sb.bytes[0]);
    std::cout << std::endl << std::endl;

    // Обмен байтов.
    temp = sb.bytes[0];
    sb.bytes[0] = sb.bytes[1];
    sb.bytes[1] = temp;

    std::cout << "Байты после перестановки: ";
    disp_binary(sb.bytes[1]);
    std::cout << " ";
    disp_binary(sb.bytes[0]);

    return 0;
}