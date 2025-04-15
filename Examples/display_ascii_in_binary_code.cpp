// Герберт Шилдт: С++ базовый курс
// Отображение ASCII-кода символов в двоичной системе счисления
// Created by Денис Скрипниченко on 15.04.2025.
//
#include <iostream>
//#include <conio.h>

// Битовые поля, которые будут расшифрованы
struct byte {
    unsigned a: 1;
    unsigned b: 1;
    unsigned c: 1;
    unsigned d: 1;
    unsigned e: 1;
    unsigned f: 1;
    unsigned g: 1;
    unsigned h: 1;
};

union bits {
    char ch;
    struct byte bit;
} ascii;

void disp_bits(bits b);

int main() {
    do {
        std::cin >> ascii.ch;
        std::cout << ascii.ch << ": ";
        disp_bits(ascii);
    } while (ascii.ch != 'q'); // Выход при вводе буквы "q".
    return 0;
}

// Отображение конфигурации битов для каждого символа
void disp_bits(bits b) {
    std::cout << b.bit.h ? "1" : "0";
    std::cout << b.bit.g ? "1" : "0";
    std::cout << b.bit.f ? "1" : "0";
    std::cout << b.bit.e ? "1" : "0";
    std::cout << b.bit.d ? "1" : "0";
    std::cout << b.bit.c ? "1" : "0";
    std::cout << b.bit.b ? "1" : "0";
    std::cout << b.bit.a ? "1" : "0";
    std::cout << std::endl;
}