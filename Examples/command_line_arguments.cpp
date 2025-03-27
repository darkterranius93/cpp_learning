// Герберт Шилдт: С++ базовый курс
// Эта программа посимвольно выводит все аргументы командной строки,
// с которыми она была вызвана
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>

int main(int argc, char *argv[]) {
    int t, i;
    for (t = 0; t < argc; t++) {
        i = 0;
        while (argv[t][i]) {
            std::cout << argv[t][i] << std::endl;
            ++i;
        }
        std::cout << " " << std::endl;
    }
    return 0;
}