// Герберт Шилдт: С++ базовый курс
// Created by Денис Скрипниченко on 02.05.2025.
//
#include <iostream>
using namespace std;

class cl {
    int i;
public:
    void load_i(int val) { this->i = val; } // то же самое, что i = val
    int get_i() { return this->i; } // то же самое, что return i
};

int main()
{
    cl o;
    o.load_i (100);
    std::cout << o.get_i() << endl;
    return 0;
}