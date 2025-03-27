// Герберт Шилдт: С++ базовый курс
// Вывод аргумента командной строки в вертикальном направлении (вниз) по левому краю экрана
// Created by Денис Скрипниченко on 27.03.2025.
//
#import <iostream>

void print_vertical(char *str);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        print_vertical(argv[1]);
    }

    return 0;
}

/**
* Вывод аргумента командной строки в вертикальном направлении (вниз) по левому краю экрана
* @param str Строка для отображения
* @return void
*/
void print_vertical(char *str) {
    while(*str) {
        std::cout << *str++ << std::endl;
    }
}
