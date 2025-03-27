// Герберт Шилдт: С++ базовый курс
// Вызов функций с массивами
// Created by Денис Скрипниченко on 25.03.2025.
//
#include <iostream>

void display(int num[10]);
void display_without_size(int num[]);
void display_by_pointer(int *num);

int main() {
    int t[10], i;
    for (i = 0; i < 10; ++i) {
        t[i] = i;
    }
    // display(t); // Передаем функции массив t
    // display_without_size(t);
    display_by_pointer(t);

    return 0;
}

/**
* Функция выводит все элементы массива
* @param num Массив, с указанной размерностью
* @return void
*/
void display(int num[10]) {
    int i;
    for (i = 0; i < 10; i++) {
      std::cout << num[i] << ' ' << std::endl;
    }
}

/**
* Функция выводит все элементы массива
* @param num Безмерный массив
* @return void
*/
void display_without_size(int num[]) {
    int i;
    for (i = 0; i < 10; i++) {
        std::cout << num[i] << ' ' << std::endl;
    }
}

/**
* Функция выводит все элементы массива
* @param num Указатель на массив
* @return void
*/
void display_by_pointer(int *num) {
    int i;
    for (i = 0; i < 10; i++) {
        std::cout << num[i] << ' ' << std::endl;
    }
}