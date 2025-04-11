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

/**
* Команда меню для ввода товаров в инвентарную ведомость
*/
void enter_command();

/**
* Команда меню для отображения на экране инвентарной ведомости
*/
void display_command();

/**
 * Команда меню для изменения существующего товара
 */
void update_command();

/**
* Команда меню для поиска и отображения данных конкретного товара
*/
void find_command();

/**
* Команда меню для удаления товара
*/
void remove_command();

/**
 * Команда меню для очистки инвентарной ведомости
 */
void clean_command();

/**
 * Ввод данных для конкретного товара
 * @param index Индекс товара
 */
void input(int index);

/**
 * Отображение в консоль данных по товару
 * @param index Индекс товара
 */
void display_item(int index);

/**
* Удаление товара
* @param index Индекс товара
*/
void delete_item(int index);

/**
* Очищение данных (удаление товара)
* @param index Индекс товара
*/
void clean_item(int index);

/**
 * Поиск товара по названию
 * @return Индекс товара | -1, если индекс не найден
 */
int find_item_index_by_name();

/**
 * Генерация тестовых данных
 */
void generate_mocks();

int main() {
    char choice;
    init_list();
    generate_mocks();

    for (;;) {
        choice = menu();
        switch (choice) {
            case 'e': enter_command(); break;
            case 'd': display_command(); break;
            case 'u': update_command(); break;
            case 'f': find_command(); break;
            case 'r': remove_command(); break;
            case 'c': clean_command(); break;
            case 'q': return 0;
        }
    }
    return 0;
}

/**
* Инициализация массива структур
*/
void init_list() {
    int index;
    // Имя нулевой длины означает пустое имя
    for (index = 0; index < SIZE; index++) {
        *invtrv[index].item = '\0';
    }
}

void generate_mocks() {
    int index;
    // Имя нулевой длины означает пустое имя
    for (index = 0; index < SIZE; index++) {
        std::string itemTitle = "Test" + std::to_string(index);
        strcpy(invtrv[index].item, itemTitle.c_str());

        invtrv[index].cost = 1.0;
        invtrv[index].retail = 1.0;
        invtrv[index].on_hand = 0;
        invtrv[index].lead_time = 0;
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
        std::cout << "(R)emove" << std::endl; // Удалить элемент
        std::cout << "(C)clean" << std::endl; // Очистить ведомость
        std::cout << "(Q)uit" << std::endl; // Выйти из программы
        std::cout << std::endl;

        std::cout << "Выберите команду: ";
        std::cin >> ch;
    } while(!strchr("eduqfrc", tolower(ch)));

    return tolower(ch);
}

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

void display_command() {
    int index;
    for (index = 0; index < SIZE; index++) {
        if (*invtrv[index].item) {
            display_item(index);
        }
    }
}

void update_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    std::cout << "Введите новую информацию." << std::endl;
    input(index);
}

void find_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    display_item(index);
}

void remove_command() {
    int index = find_item_index_by_name();

    if (index == UNKNOWN_INDEX) {
        std::cout << "Товар не найден." << std::endl;
        return;
    }

    delete_item(index);
}

void clean_command() {
    int index;
    for (index = 0; index < SIZE; index++) {
        if (*invtrv[index].item) {
            clean_item(index);
        }
    }
}

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
void input(const int index) {
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
void display_item(const int index) {
    if (!*invtrv[index].item) {
        return;
    }
    std::cout << invtrv[index].item << std::endl;
    std::cout << "Стоимость: $" << invtrv[index].cost << std::endl;
    std::cout << "В розницу: $" << invtrv[index].retail << std::endl;
    std::cout << "В наличии: " << invtrv[index].on_hand << std::endl;
    std::cout << "До пополнения осталось: " << invtrv[index].lead_time << " дней" << std::endl << std::endl;
}

void delete_item(const int index) {
    if (!*invtrv[index].item) {
        return;
    }

    // Очищение данных (удаление товара)
    clean_item(index);

    // Если за товаром находился другой - сдвигаем его на место текущего
    // и рекурсивно идем и сдвигаем следующие в списке
    while (*invtrv[index+1].item) {
        invtrv[index] = invtrv[index+1];
        delete_item(index+1);
    }
}

void clean_item(const int index) {
    *invtrv[index].item = '\0';
    invtrv[index].cost = 0.0;
    invtrv[index].retail = 0.0;
    invtrv[index].on_hand = 0;
    invtrv[index].lead_time = 0;
}

