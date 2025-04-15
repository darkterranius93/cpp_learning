// Герберт Шилдт: С++ базовый курс
// Отображение конфигурации битов в байте
// Created by Денис Скрипниченко on 03.04.2025.
//
#import <iostream>

void disp_binary(unsigned u);

void disp_binary(unsigned u) {
    // register int t;
    int t;
    for (t = 128; t > 0; t = t/2) {
        if (u & t) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}