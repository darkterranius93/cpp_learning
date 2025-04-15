// Герберт Шилдт: С++ базовый курс
// Демонстрация выполнения поразрядного сдвига
// Created by Денис Скрипниченко on 03.04.2025.
//
#import <iostream>
#import "disp_binary.cpp"

int main() {
    int i = 1, t;
    std::cout << "operator '<<':" << std::endl;
    for (t = 0; t < 8; t++) {
        disp_binary(i);
        std::cout << std::endl;
        i = i << 1;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "operator '>>':" << std::endl;
    for (t = 0; t < 8; t++) {
        i = i >> 1;
        disp_binary(i);
        std::cout << std::endl;
    }
}
