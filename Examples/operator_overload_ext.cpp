// Герберт Шилдт: С++ базовый курс
// Created by Денис Скрипниченко on 02.05.2025.
//
#include <iostream>
using namespace std;

class CL {
public:
    int count;
    CL operator=(CL obj);
    friend CL operator+(CL ob, int i);
    friend CL operator+(int i, CL ob);
};

CL CL::operator=(CL obj)
{
    count = obj.count;
    return *this;
}

// Эта версия обрабатывает аргументы
// объект + int-значение.
CL operator+(CL ob, int i)
{
    CL temp;
    temp.count = ob.count + i;
    return temp;
}

// Эта версия обрабатывает аргументы
// int-значение + объект.
CL operator+(int i, CL ob)
{
    CL temp;
    temp.count = ob.count + i;
    return temp;
}

int main()
{
    CL o;
    o.count = 10;
    cout << o.count << " "; // выводит число 10
    o=10+o; // сложение числа с объектом
    cout << o.count << " "; // выводит число 20
    o=o+12; // сложение объекта с числом
    cout << o.count; // выводит число 32

    return 0;
}