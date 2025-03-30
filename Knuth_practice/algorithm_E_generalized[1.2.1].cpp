// Дональд Кнут. Искусство программирования. Том 1.
// Раздел 1.2.1
// Алгоритм E (обобщённый алгоритм Евклида)
// Created by Денис Скрипниченко on 16.03.2025.
//
#include <iostream>
#include <ostream>

/**
 * Алгоритм:
 * Даны два целых положительных числа m и n.
 * Требуется найти их общий делитель *d и два целых
 * числа a и b, таких что am + bn = d
 */

/**
 * Структура для хранения результата
 * выполнения алгоритма
 */
struct algorithm_result {
    int d;
    int a;
    int b;
};

/**
 * Обобщённый алгоритм Евклида:
 * нахождение наибольшего общего делителя
 * @param int m
 * @param int n
 * @return int
 */
algorithm_result algorithm_E_generalized(int m, int n);

/**
 * Структура для хранения тестовых данных
 * Обобщённого алгоритма Евклида и верного результата его выполнения
 */
struct TestNumbersPair {
    int m;
    int n;
    algorithm_result result;
};

/**
 * Функция для тестирования обобщённого алгоритма Евклида
 * 'int algorithm_E_generalized(int m, int n)'
 * @param testNumbersPair Массив тестовых данных
 * @param count Количество элементов в массиве 'testNumbersPair'
 * @return
 */
bool test_algorithm_E_generalized(TestNumbersPair testNumbersPair[], int count);

int main() {
    TestNumbersPair pairs[1] = {
        {1769, 551, {29, 5, -16}}
    };

    bool result = test_algorithm_E_generalized(pairs, 1);

    if (result) {
        std::cout << "Test passed";
    } else {
        std::cout << "Test failed";
    }

    return 0;
}

algorithm_result algorithm_E_generalized(int m, int n) {
    // Обозначения:
    // a = algorithm_result.a, b = algorithm_result.b, d = algorithm_result.d
    // a' = int.a, b' = int.b
    algorithm_result result;
    int a, b, c, r, q, t;

    // E1. Инициализация
    // Присвоить a' <- b <- 1, a <- b' <- 0,
    // c <- m, d <- n;
    result.b = 1;
    a = 1;

    b = 0;
    result.a =0;

    c = m;
    result.d = n;

    while (true) {
        // E2. Деление
        // Пусть q и r - это частное и остаток от деления
        // c на d соответственно (тогда c = qd + r, где 0 <= r < d)
        r = c % result.d;
        q = int(c / result.d);

        std::cout << "a'=" << a;
        std::cout << ", a=" << result.a;
        std::cout << ", b'=" << b;
        std::cout << ", b=" << result.b;
        std::cout << ", c=" << c;
        std::cout << ", d=" << result.d;
        std::cout << ", q=" << q;
        std::cout << ", r=" << r;
        std::cout << std::endl;

        // E3. Остаток - нуль?
        // Если r = 0, то выполнение алгоритма прекращается
        // в этом случае имеем am + bm = d, как и требовалось
        if (r == 0) {
            break;
        }

        // E4. Повторение цикла
        // Присвоить:
        // с <- d, d <- r
        // t <- a', a' <- a, a <- t - qa
        // t <- b', b' <- b, b <- t - qb
        // и вернуться к шагу E2
        c = result.d;
        result.d = r;

        t = a;
        a = result.a;
        result.a = t - q * result.a;

        t = b;
        b = result.b;
        result.b = t - q*result.b;
    }

    return result;
}

bool test_algorithm_E_generalized(TestNumbersPair testNumbersPair[], int count) {
    bool testResult = false;

    for (int i = 0; i < count; i++) {
        TestNumbersPair pair = testNumbersPair[i];
        algorithm_result result = algorithm_E_generalized(pair.m, pair.n);

        testResult = testResult || (result.d == pair.result.d && result.a == pair.result.a && result.b == pair.result.b);

        std::cout << "m="<<pair.m << ", n=" << pair.n << ", d(divisor)="<< pair.result.d << ", a=" << pair.result.a << ", b=" << pair.result.b << std::endl;
        std::cout << "algorithm_E_generalized(" << pair.m << ", " << pair.n << ")= " << "d(divisor)="<< result.d << ", a=" << result.a << ", b=" << result.b;

        std::cout << std::endl << std::endl;
    }

    return testResult;
}