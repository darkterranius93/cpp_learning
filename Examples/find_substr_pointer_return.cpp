// Герберт Шилдт: С++ базовый курс
// Новая версия функции find_substr().
// которая возвращает указатель на строку
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>

char *find_substr(char *sub, char *str);

int main() {
    char *substr;
    substr = find_substr("three", "one two three four");
    std::cout << "Найденная подстрока: " << substr << std::endl;

    return 0;
}

/**
* Функция возвращает указатель на искомую подстроку иили нуль
* если таковая не будет найдена
* @param sub Искомая строка
* @param str Строка, в которой производится поиск
* @return char*
*/
char *find_substr(char *sub, char *str) {
    int t;
    char *p, *p2, *start;

    for (t = 0; str[t]; t++) {
        p = &str[t]; // установка указателей
        start = p;
        p2 = sub;

        while (*p2 && *p2==*p) { // проверка совпадения
            p++; p2++;
        }

        /* Если достигнут конец p2-строки (т.е. подстроки), то подстрока была найдена */
        if (!*p2) {
            return start; // Возвращаем указатель на начало найденной подстроки
        }
    }

    return 0; // подстрока не найдена
}