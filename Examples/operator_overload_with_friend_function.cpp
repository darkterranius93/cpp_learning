// Герберт Шилдт: С++ базовый курс
// Перегрузка оператора "+" с помощью функции-"друга"
// Created by Денис Скрипниченко on 02.05.2025.
//
#include <iostream>
using namespace std;

class three_d {
    int x, y, z; // 3-мерные координаты

    public:
    three_d() { x = y = z = 0; }
    three_d(int i, int j, int k) {x = i; y = j; z = k; }

    three_d operator=(three_d op2); // Операнд op1 передается неявно.
    friend three_d operator+(three_d op1, three_d op2);

    // Эти функции для перегрузки
    // оператора "++" используют ссылочные параметры.
    friend three_d operator++(three_d &op1);
    friend three_d operator++(three_d &op1, int notused);

    void show();
};

// Перегрузка оператора присваивания.
three_d three_d::operator=(three_d op2)
{
    x = op2.x; // Операции присваивания целочисленных
    y = op2.y; // значений сохраняют оригинальный
    z = op2.z; // смысл.
    return *this;
}


// Перегрузка оператора "+" с помощью функции-"друга"
three_d operator+(three_d op1, three_d op2)
{
    three_d temp;
    temp.x = op1.x + op2.x;
    temp.y = op1.y + op2.y;
    temp.z = op1.z + op2.z;
    return temp;
}

/* Перегрузка префиксной версии оператора "++" с использованием функции-"друга".
Для этого необходимо использование ссылочного параметра.
*/
three_d operator++(three_d &op1)
{
    op1.x++;
    op1.y++;
    op1.z++;
    return op1;
}

/* Перегрузка постфиксной версии оператора "++" с использованием функции-"друга".
Для этого необходимо использование ссылочного параметра.
*/
three_d operator++(three_d &op1, int notused)
{
    three_d temp = op1;
    op1.x++;
    op1.y++;
    op1.z++;
    return temp;
}

// Отображение координат X, Y, Z.
void three_d::show()
{
    cout << x << ",";
    cout << y << ",";
    cout << z << "\n";
}

int main()
{
    three_d a(1, 2, 3), b(10, 10, 10), c;
    a.show();
    b.show();
    cout << endl;

    c = a + b; // сложение объектов а и b
    c.show();
    cout << endl;

    c=a+b+c; // сложение объектов a, b и с
    c.show();
    cout << endl;

    c = b = a; // демонстрация множественного присваивания
    c.show();
    b.show();

    ++c; // префиксная версия инкремента
    c.show();

    c++; // постфиксная версия инкремента
    c. show();

    a = ++c; // Объект а получает значение объекта с после инкрементирования.
    a.show(); // В этом случае объекты а и с
    c.show(); // имеют одинаковые значения координат.

    a = c++; // Объект а получает значение объекта с до инкрементирования.
    a.show(); // В этом случае объекты а и с
    c.show(); // имеют различные значения координат.

    return 0;
}