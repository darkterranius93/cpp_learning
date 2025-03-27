// Герберт Шилдт: С++ базовый курс
// Простая программа-тренажер по выполнению сложения.
// Created by Денис Скрипниченко on 25.03.2025.
//
#include <iostream>
#include <cstdlib>

void drill();
int count;  // Переменные count и num_right - глобальные
int num_right;

int main() {
    std::cout << "Сколько практических упражнений: ";
    std::cin >> count;
    num_right = 0;

    do {
        drill();
        count--;
    } while(count);

    std::cout << "Вы дали " << num_right << " правильных ответов." << std::endl;
    return 0;
}

void drill() {
   int count; /* Это переменная count - локальная и никак не связана с глобальной */
   int a, b, ans;

   // Генерируются два числа между 0 и 99.
   a = rand() % 100;
   b = rand() % 100;

   // Пользователь получает три попытки дать правильный ответ
   for (count = 0; count < 3; count++) {
       std::cout << "Сколько будет "<< a << " + " << b << "? ";
       std::cin >> ans;
       if (ans == a + b) {
           std::cout << "Правильно" << std::endl;
           num_right++;
           return;
       }
   }

   std::cout << "Вы использовали все свои попытки." << std::endl;
   std::cout << "Ответ равен " << a + b << std::endl;
}