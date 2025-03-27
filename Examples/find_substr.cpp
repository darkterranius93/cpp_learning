// Герберт Шилдт: С++ базовый курс
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>

int find_substr(char *sub, char *str);

int main() {
    int index;
    index = find_substr("three", "one two three four");

    std::cout << "Индекс равен " << index << std::endl; // Индекс равен 8
    return 0;
}

/**
* Функция возвращает индекс искомой подстроки или -1,
* если она не была найдена
* @param sub Искомая строка
* @param str Строка, в которой производится поиск
* @return index (N | -1)
*/
int find_substr(char *sub, char *str) {
    int t;
    char *p, *p2;

    for (t = 0; str[t]; t++) {
        p = &str[t]; // установка указателей
        p2 = sub;

        while (*p2 && *p2==*p) { // проверка совпадения
            p++; p2++;
        }

        /* Если достигнут конец p2-строки (т.е. подстроки), то подстрока была найдена */
        if (!*p2) {
            return t; // Возвращаем индекс подстроки
        }
    }

    return -1;
}