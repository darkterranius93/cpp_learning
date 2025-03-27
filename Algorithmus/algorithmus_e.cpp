//
// Created by Денис Скрипниченко on 16.03.2025.
//

#include <iostream>
#include <ostream>

/**
 * Алгоритм Евклида:
 * нахождение наибольшего общего делителя
 * @param int m
 * @param int n
 * @return int
 */
int algorithmus_e(int m, int n);

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
 * 'int algorithmus_e(int m, int n)'
 * @param testNumbersPair Массив тестовых данных
 * @param count Количество элементов в массиве 'testNumbersPair'
 * @return
 */
bool test_algorithmus_e(struct TestNumbersPair testNumbersPair[], int count);

int main() {
    TestNumbersPair pairs[3] = {
        {119, 544, 17},
        {10, 5, 5},
        {12, 9, 3}
    };

    std::cout << sizeof(pairs) << std::endl;
    bool result = test_algorithmus_e(pairs, 3);

    if (result) {
        std::cout << "Test passed";
    } else {
        std::cout << "Test failed";
    }

    return 0;
}

int algorithmus_e(int m, int n) {
    int r;
    while (true) {
        r = m % n;
        if (r == 0) {
            break;
        }
        m = n;
        n = r;
    }
    return n;
}

bool test_algorithmus_e(struct TestNumbersPair testNumbersPair[], int count) {
    bool result = false;

    for (int i = 0; i < count; i++) {
        TestNumbersPair pair = testNumbersPair[i];
        int divisor = algorithmus_e(pair.m, pair.n);
        result = result || (divisor == pair.maxCommonDivisor);
        std::cout << "m="<<pair.m << ", n=" << pair.n << ", divisor="<< pair.maxCommonDivisor << std::endl;
        std::cout << "algorithmus_e(" << pair.m << ", " << pair.n << ")=" << divisor;

        std::cout << std::endl << std::endl;
    }

    return result;
}