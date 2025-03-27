// Герберт Шилдт: С++ базовый курс
// Преобразование каждого элемента массива в куб этого значения
// Created by Денис Скрипниченко on 27.03.2025.
//
#include <iostream>

void cube(int *n, int num);

int main() {
    int i, nums[10];
    for (i = 0; i < 10; i++) {
        nums[i] = i + 1;
    }

    std::cout << "Исходное содержимое массива: ";
    for (i = 0; i < 10; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    cube(nums, 10); // Вычисляем кубы значений
    std::cout << "Изменённое содержимое массива: ";
    for (i = 0; i < 10; i++) {
        std::cout << nums[i] << " ";
    }

    return 0;
}

void cube(int *n, int num) {
    while (num) {
        *n = *n * *n * *n;
        num--;
        n++;
    }
}