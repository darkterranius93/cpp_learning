// Герберт Шилдт: С++ базовый курс
// Отображение строки в обратном порядке с помощью рекурсии.
// Created by Денис Скрипниченко on 31.03.2025.
//
#include <iostream>

void reverse(char *s);

int main() {
    char str[] = "Hello World!";
    reverse(str);
    return 0;
}

// Вывод строки в обратном порядке
void reverse(char *s) {
    if (*s) {
       reverse(s+1);
    } else {
        return;
    }
    std::cout << *s << std::endl;
}