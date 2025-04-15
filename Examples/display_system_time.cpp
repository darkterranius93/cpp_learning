// Герберт Шилдт: С++ базовый курс
// Эта программа отображает текущее системное время
// Created by Денис Скрипниченко on 15.04.2025.
//
#import <iostream>
#include <ctime>

int main() {
    struct tm *ptr;
    time_t lt;

    lt = time(NULL);
    ptr = localtime(&lt);

    std::cout << ptr->tm_hour << ":" << ptr->tm_min << ":" << ptr->tm_sec;

    return 0;
}