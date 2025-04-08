// Герберт Шилдт: С++ базовый курс
// Простой пример инвентаризации склада
// Created by Денис Скрипниченко on 04.04.2025.
//
#include <iostream>

const int SIZE = 100;

struct inv_type {
    char item[40]; // наименование товара
    double cost; // стоимость
    double retail; // розничная цена
    int on_hand; // имеющееся в наличии количество
    int lead_time; // число дней до пополнения запасов
} invtrv[SIZE];

void init_list();
int menu();
void enter();
void input(int i);
void display();
void update();

int main() {
    char choice;
    init_list();

    for (;;) {
        choice = menu();
        switch (choice) {
            case 'e': enter(); break;
            case 'd': display(); break;
            case 'u': update(); break;
            case 'q': return 0;
        }
    }
    return 0;
}

// Инициализация массива структур
void init_list() {
    int t;
    // Имя нулевой длины означает пустое имя
    for (t = 0; t < SIZE; t++) {
        *invtrv[t].item = '\0';
    }
}

// Получение команды меню, выбранной пользователем
int menu() {
    char ch;
    std::cout << std::endl;

    do {
        std::cout << "(E)nter" << std::endl; // Ввести новый элемент
        std::cout << "(D)isplay" << std::endl; // Отобразить всю ведомость
        std::cout << "(U)pdate" << std::endl; // Изменить элемент
        std::cout << "(Q)uit" << std::endl; // Выйти из программы
        std::cout << std::endl;

        std::cout << "Выберите команду: ";
        std::cin >> ch;
    } while(!strchr("eduq", tolower(ch)));

    return tolower(ch);
}

// Ввод элементов в инвентарную ведомость
void enter() {
    int i;

    // Находим первую свободную структуру
    for (i = 0; i < SIZE; i++) {
        if (!*invtrv[i].item) {
            break;
        }
    }

    // Если массив полон, значение i будет равно SIZE
    if (i == SIZE) {
        std::cout << "Список полон" << std::endl;
        return;
    }
    input(i);
}

// Ввод информации
void input(int i) {
    std::cout << "Товар: ";
    std::cin >> invtrv[i].item;

    std::cout << "Стоимость: ";
    std::cin >> invtrv[i].cost;

    std::cout << "Розничная цена: ";
    std::cin >> invtrv[i].retail;

    std::cout << "В наличии: ";
    std::cin >> invtrv[i].on_hand;

    std::cout << "Время до пополнения запасов (в днях): ";
    std::cin >> invtrv[i].lead_time;
}

// Модификация существующего элемента
void update() {
    int i;
    char name[80];

    std::cout << "Введите наименование товара: " << std::endl;
    std::cin >> name;

    for (i = 0; i < SIZE; i++) {
        if (!strcmp(name, invtrv[i].item)) {
            break;
        }
    }

    if (i == SIZE) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    std::cout << "Введите новую информацию." << std::endl;
    input(i);
}

// Отображение на экране инвентарной ведомости
void display() {
    int t;
    for (t = 0; t < SIZE; t++) {
        if (*invtrv[t].item) {
            std::cout << invtrv[t].item << std::endl;
            std::cout << "Стоимость: $" << invtrv[t].cost << std::endl;
            std::cout << "В розницу: $" << invtrv[t].retail << std::endl;
            std::cout << "В наличии: " << invtrv[t].on_hand << std::endl;
            std::cout << "До пополнения осталось: " << invtrv[t].lead_time << " дней" << std::endl << std::endl;
        }
    }
}