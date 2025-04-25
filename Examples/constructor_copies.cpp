// Герберт Шилдт: С++ базовый курс
//  Использование конструктора копии для определения параметра
// Created by Денис Скрипниченко on 25.04.2025.
//
#include <iostream>
#include <cstdlib>

class myclass {
    int *p;

    public:
        myclass(int i); // обычный конструктор
        myclass(const myclass &ob); // конструктор копии
        ~myclass();
        int getval() { return *p; }
};

class myclass2 {
public:
    myclass2() { std::cout << "Обычный конструктор.\n"; }
    myclass2(const myclass2 &obj) { std::cout << "Конструктор копии.\n"; }
};

// Конструктор копии.
myclass::myclass(const myclass &obj)
{
    std::cout << "Вызван конструктор копии.\n";
    this->p = new int;
    *p = *obj.p; // значение копии
}

// Обычный конструктор.
myclass::myclass(int i)
{
    std::cout << "Вызван обычный конструктор.\n";
    std::cout << "Выделение памяти, адресуемой указателем p.\n";
    this->p = new int;
    *p = i;
}

myclass::~myclass()
{
    std::cout <<"Освобождение памяти, адресуемой указателем p.\n";
    delete p;
}

// Эта функция принимает один объект-параметр.
void display(myclass ob)
{
    std::cout << ob.getval() << '\n';
}

myclass2 f()
{
    myclass2 ob; // Вызывается обычный конструктор.
    return ob; // Неявно вызывается конструктор копии.
}

int main()
{
    myclass a(10); // Вызывается обычный конструктор.
    display(a); // Вызывается конструктор копии.
    myclass b = a; // Вызывается конструктор копии.

    myclass2 c;
    c = f(); // Почему-то не вызывается конструктор копии, хотя по книге должен

    // myclass c(10); myclass b(10); b = c; // конструктор копии не будет вызван,
    // т.к. выполняется операция присваивания, а не копирования
    return 0;
}