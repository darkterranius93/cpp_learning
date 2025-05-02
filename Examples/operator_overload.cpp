// Герберт Шилдт: С++ базовый курс
// Перегрузка операторов с помощью функций-членов.
// Created by Денис Скрипниченко on 02.05.2025.
//
#include <iostream>
using namespace std;

class three_d {
    int x, y, z; // 3-мерные координаты

    public:
    three_d() { x = y = z = 0; }
    three_d(int i, int j, int k) {x = i; y = j; z = k; }

    three_d operator+(three_d op2); // Операнд op1 передается  неявно.
    three_d operator=(three_d op2); // Операнд op1 передается неявно.
    three_d operator++(); // префиксная версия оператора ++
    three_d operator++(int notused); // постфиксная версия оператора ++

    void show();
};

// Перегрузка оператора "+"
three_d three_d::operator+(three_d op2)
{
    three_d temp;
    temp.x = x + op2.x; // Операции сложения целочисленных
    temp.y = y + op2.y; // значений сохраняют оригинальный
    temp.z = z + op2.z; // смысл.
    return temp;
}

// Перегрузка оператора присваивания.
three_d three_d::operator=(three_d op2)
{
    x = op2.x; // Операции присваивания целочисленных
    y = op2.y; // значений сохраняют оригинальный
    z = op2.z; // смысл.
    return *this;
}

// Отображение координат X, Y, Z.
void three_d::show()
{
    cout << x << ",";
    cout << y << ",";
    cout << z << "\n";
}

// Перегруженная префиксная версия оператора "++"
three_d three_d::operator++()
{
    x++; // инкремент координат х, у и z
    y++;
    z++;
    return *this;
}

// Перегруженная префиксная версия оператора "++"
three_d three_d::operator++(int notused)
{
    three_d temp = *this; // сохранение исходного значения

    x++; // инкремент координат х, у и z
    y++;
    z++;
    return temp;
}


int main()
{
    three_d a(1, 2, 3), b(10, 10, 10), c;
    a.show();
    b.show();

    c=a+b; // сложение объектов а и b
    c.show();

    c=a+b+c; // сложение объектов a, b и с
    c.show();

    c=b=a; // демонстрация множественного присваивания
    c.show();
    b.show();

    ++c; // префиксная форма инкремента
    c.show();

    c++; // постфиксная форма инкремента
    c.show();

    a = ++c; // Объект а получает значение объекта с после его инкрементирования.
    a.show(); // Теперь объекты а и с
    c.show(); // имеют одинаковые значения.

    a = c++; // Объект а получает значение объекта с до его инкрементирования.
    a.show(); // Теперь объекты а и с
    c.show(); // имеют различные значения.

    return 0;
}