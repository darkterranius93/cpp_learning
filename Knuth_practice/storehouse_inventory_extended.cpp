// Герберт Шилдт: С++ базовый курс
// Простой пример инвентаризации склада
// Практическое задание. Расширить программу, добавив функции:
// - поиска в списке заданного товара;
// - удаления уже ненужного элемента;
// - полной очистки инвентарной ведомости.
// Created by Денис Скрипниченко on 04.04.2025.
//
#include <iostream>

const int SIZE = 100;
const int UNKNOWN_INDEX = -1;

struct inv_type {
    char item[40]; // наименование товара
    double cost; // стоимость
    double retail; // розничная цена
    int on_hand; // имеющееся в наличии количество
    int lead_time; // число дней до пополнения запасов
} invtrv[SIZE];

void init_list();
int menu();
void enter_command();
void display_command();
void update_command();
void find_command();
void remove_command();
void input(int index);
void display_item(int index);
void delete_item(int index);
void move_item(int from_index, int to_index);
int find_item_index_by_name();

int main() {
    char choice;
    init_list();

    for (;;) {
        choice = menu();
        switch (choice) {
            case 'e': enter_command(); break;
            case 'd': display_command(); break;
            case 'u': update_command(); break;
            case 'f': find_command(); break;
            case 'r': remove_command(); break;
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

/**
* Получение команды меню, выбранной пользователем
*/
int menu() {
    char ch;
    std::cout << std::endl;

    do {
        std::cout << "(E)nter" << std::endl; // Ввести новый элемент
        std::cout << "(D)isplay" << std::endl; // Отобразить всю ведомость
        std::cout << "(U)pdate" << std::endl; // Изменить элемент
        std::cout << "(F)ind" << std::endl; // Найти элемент
        std::cout << "(R)emove" << std::endl; // Найти элемент
        std::cout << "(Q)uit" << std::endl; // Выйти из программы
        std::cout << std::endl;

        std::cout << "Выберите команду: ";
        std::cin >> ch;
    } while(!strchr("eduqfr", tolower(ch)));

    return tolower(ch);
}

/**
* Ввод элементов в инвентарную ведомость
*/
void enter_command() {
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

/**
* Отображение на экране инвентарной ведомости
*/
void display_command() {
    int t;
    for (t = 0; t < SIZE; t++) {
        if (*invtrv[t].item) {
            display_item(t);
        }
    }
}

// Модификация существующего элемента
void update_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    std::cout << "Введите новую информацию." << std::endl;
    input(index);
}

/**
* Поиск и отображение данных конкретного товара
*/
void find_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    display_item(index);
}

/**
* Удаление товара
*/
void remove_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    delete_item(index);
}

/**
* @return int Индекс товара | -1, если индекс не найден
*/
int find_item_index_by_name() {
    int i;
    char name[80];

    std::cout << "Введите наименование товара: ";
    std::cin >> name;

    for (i = 0; i < SIZE; i++) {
        if (!strcmp(name, invtrv[i].item)) {
            return i;
        }
    }

    return UNKNOWN_INDEX;
}

/**
* Ввод информации товара
* @param int индекс
*/
void input(int index) {
    std::cout << "Товар: ";
    std::cin >> invtrv[index].item;

    std::cout << "Стоимость: ";
    std::cin >> invtrv[index].cost;

    std::cout << "Розничная цена: ";
    std::cin >> invtrv[index].retail;

    std::cout << "В наличии: ";
    std::cin >> invtrv[index].on_hand;

    std::cout << "Время до пополнения запасов (в днях): ";
    std::cin >> invtrv[index].lead_time;
}

/**
* Отображение данных товара
*/
void display_item(int index) {
    if (!*invtrv[index].item) {
        return;
    }
    std::cout << invtrv[index].item << std::endl;
    std::cout << "Стоимость: $" << invtrv[index].cost << std::endl;
    std::cout << "В розницу: $" << invtrv[index].retail << std::endl;
    std::cout << "В наличии: " << invtrv[index].on_hand << std::endl;
    std::cout << "До пополнения осталось: " << invtrv[index].lead_time << " дней" << std::endl << std::endl;
}

/**
* Удаление товара
*/
void delete_item(int index) {
    if (!*invtrv[index].item) {
        return;
    }

    // Очищение данных (удаление товара)
    //*invtrv[index].item = '\0';

    double *cost = &invtrv[index].cost;
    cost = new double;

    double *retail = &invtrv[index].retail;
    retail = new double;

    int *on_hand = &invtrv[index].on_hand;
    on_hand = new int;

    int *lead_time = &invtrv[index].lead_time;
    lead_time = new int;

    // Если за товаром находился другой - сдвигаем
    while (*invtrv[index+1].item && index < SIZE) {
          move_item(index+1, index);
          index++;
    }
}

/**
* Изменение позиции (индекса) товара
* @param int с позиции (индекса)
* @param int на позицию (индекс)
*/
void move_item(int from_index, int to_index) {

}