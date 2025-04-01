// Герберт Шилдт: С++ базовый курс
// Пример использования рекурсивных функций
// Created by Денис Скрипниченко on 31.03.2025.
//
#include <iostream>

int factorial_recursion(int n);
int factorial_iterative(int n);

int main() {
    // Использование рекурсивной версии
    std::cout << "Факториал числа 4 равен " << factorial_recursion(4) << std::endl;

    // Использование итеративной версии
    std::cout << "Факториал числа 4 равен " << factorial_iterative(4) << std::endl;


    return 0;
}

// Рекурсивная версия
int factorial_recursion(int n) {
    int answer;
    if (n == 1) {
        return 1;
    }
    answer = factorial_recursion(n - 1) * n;
    return answer;
}

// Итеративная версия
int factorial_iterative(int n) {
    int t, answer;
    answer = 1;
    for (t = 1; t <= n; t++) {
      answer = answer * t;
    }
    return answer;
}