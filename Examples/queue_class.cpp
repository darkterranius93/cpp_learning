// Герберт Шилдт: С++ базовый курс
// Пример класса queue (очередь FIFO)
// Created by Денис Скрипниченко on 15.04.2025.
//
#include <iostream>

// Создание класса queue
class queue {
    int q[100];
    int sloc, rloc;
    int who; // содержит идентификационный номер очереди

    public:
    queue(int id); // параметризированный конструктор
    ~queue(); // деструктор
    void init();
    void qput(int i);
    int gget();
};

// Определение конструктора
queue::queue(int id) {
  	who = id;
	init();
    std::cout << "Очередь " << who << " инициализирована" << std::endl;
}

// Определение деструктора
queue::~queue() {
	std::cout << "Очередь " << who << " разрушена" << std::endl;
}

// Инициализация класса queue
void queue::init() {
    rloc = sloc = 0;
}

// Занесение в очередь целочисленного значения
void queue::qput(int i) {
    if (sloc == 100) {
       std::cout << "Очередь заполнена" << std::endl;
       return;
    }

    sloc++;
    q[sloc] = i;
}

// Извлечение из очереди целочисленного значения
int queue::gget() {
    if (rloc == sloc) {
        std::cout << "Очередь пуста" << std::endl;
        return 0;
    }

    rloc++;
    return q[rloc];
}

int main() {
  	// Создание двух объектов класса queue.
  	queue a = queue(1);
  	queue b = queue(2);

    a.init();
    b.init();

    a.qput(10);
    b.qput(19);

    a.qput(20);
    b.qput(1);

    std::cout << "Содержимое очереди 1: ";
    std::cout << a.gget() << " " << a.gget() << std::endl;

    std::cout << "Содержимое очереди 2: ";
    std::cout << b.gget() << " " << b.gget() << std::endl;

	return 0;
}