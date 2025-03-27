// Герберт Шилдт: С++ базовый курс
// Простая памятка по ключевым словам C++
// Created by Денис Скрипниченко on 25.03.2025.
#include <iostream>
#include <cstring>

char *keyword[][2] = {
    "for", "for(инициализация; условие; инкремент)",
    "if", "if(условие) ... else ...",
    "switch", "switch(значение) {case-список}",
    "while", "while(условие) ...",
    // Сюда нужно добавить остальные ключевые слова C++
    "", "" // Список должен заканчиваться нулевыми строками.
};

int main() {
    char str[80];
    int i;

    std::cout << "Введите ключевое слово: ";
    std::cin >> str;

    // Отображаем синтаксис
    for (i = 0; *keyword[i][0]; i++) {
        if (!strcmp(keyword[i][0], str)) {
            std::cout << keyword[i][1];
        }
    }
    return 0;
}
