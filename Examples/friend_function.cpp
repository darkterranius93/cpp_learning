// Герберт Шилдт: С++ базовый курс
// Использование функции-"друга"
// Created by Денис Скрипниченко on 18.04.2025.
//
#include <iostream>

const int IDLE=0;
const int INUSE=1;

class C2; // опережающее объявление
class C1 {
    int status; // IDLE если сообщение неактивно, INUSE если сообщение выыведено на экран

    public:
        void set_status(int state);
        friend int idle(C1 a, C2 b);
};

class C2 {
    int status; // IDLE если сообщение неактивно, INUSE если сообщение выыведено на экран


    public:
       void set_status(int state);
       friend int idle(C1 a, C2 b);
};

void C1::set_status(int state) {
    status = state;
}

void C2::set_status(int state) {
    status = state;
}

// Функция idle() - "друг" для классов C1 и C2
int idle(C1 a, C2 b) {
    if (a.status || b.status) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    C1 x;
    C2 y;

    x.set_status(IDLE);
    y.set_status(IDLE);

    if (idle(x, y)) {
        std::cout << "Экран свободен." << std::endl;
    } else {
        std::cout << "Отображается сообщение." << std::endl;
    }

    x.set_status(INUSE);

    if (idle(x, y)) {
        std::cout << "Экран свободен." << std::endl;
    } else {
        std::cout << "Отображается сообщение." << std::endl;
    }

    return 0;
}