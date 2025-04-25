// Герберт Шилдт: С++ базовый курс
// Использование перегруженных конструкторов
// Created by Денис Скрипниченко on 25.04.2025.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

class timer {
    int seconds;

    public:
      // секунды, задаваемые в виде строки
      timer(char *t) { seconds = atoi(t); }

      // секунды, задаваемые в виде целого числа
      timer(int t) { seconds = t; }

      // время, задаваемое в минутах и секундах
      timer(int min, int sec) { seconds = min * 60 + sec; }

      void run();
};

void timer::run() {
    clock_t t1;
    t1 = clock();
    while ( (clock() / CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC) < seconds) { }
    std::cout << "\a"; // звуковой сигнал
}

int main() {
    timer a(10), b("20"), c(1, 10);

    a.run(); // отсчет 10 секунд
    b.run(); // отсчет 20 секунд
    c.run(); // отсчет 1 минуты и 10 секунд

    return 0;
}