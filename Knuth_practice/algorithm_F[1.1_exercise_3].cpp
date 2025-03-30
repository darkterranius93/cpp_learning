// Дональд Кнут. Искусство программирования. Том 1.
// Раздел 1.1. Упражнение 3 [20]
// Алгоритм F (алгоритм Евклида)
// Created by Денис Скрипниченко on 16.03.2025.
//
#include <iostream>
#include <ostream>

/**
 * Алгоритм:
 * Даны два целых положительных числа m и n.
 * Требуется найти их общий делитель.
 */

/**
 * Алгоритм F (алгоритм Евклида)
 * нахождение наибольшего общего делителя
 * @param int m
 * @param int n
 * @return int
 */
int algorithm_F(int m, int n);

/**
 * Структура для хранения тестовых данных
 * Алгоритма Евклида и верного результата его выполнения
 */
struct TestNumbersPair {
    int m;
    int n;
    int maxCommonDivisor;
};

/**
 * Функция для тестирования алгоритма Евклида
 * 'int algorithm_F(int m, int n)'
 * @param testNumbersPair Массив тестовых данных
 * @param count Количество элементов в массиве 'testNumbersPair'
 * @return
 */
bool test_algorithm_F(TestNumbersPair testNumbersPair[], int count);

int main() {
    TestNumbersPair pairs[3] = {
        {119, 544, 17},
        {10, 5, 5},
        {12, 9, 3}
    };

    std::cout << sizeof(pairs) << std::endl;
    bool result = test_algorithm_F(pairs, 3);

    if (result) {
        std::cout << "Test passed";
    } else {
        std::cout << "Test failed";
    }

    return 0;
}

int algorithm_F(int m, int n) {
    while (true) {
        m = m % n;
        if (m == 0) {
            return n;
        }

        n = n % m;
        if (n == 0) {
            return m;
        }
    }
}

bool test_algorithm_F(TestNumbersPair testNumbersPair[], int count) {
    bool result = true;

    for (int i = 0; i < count; i++) {
        TestNumbersPair pair = testNumbersPair[i];
        int divisor = algorithm_F(pair.m, pair.n);
        result = result && (divisor == pair.maxCommonDivisor);
        std::cout << "m="<<pair.m << ", n=" << pair.n << ", divisor="<< pair.maxCommonDivisor << std::endl;
        std::cout << "algorithm_F(" << pair.m << ", " << pair.n << ")=" << divisor;

        std::cout << std::endl << std::endl;
    }

    return result;
}