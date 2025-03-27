// Герберт Шилдт: С++ базовый курс
// Простая программа ведения базы данных служащих
#include <iostream>

char name[10][80]; // Массив имен служащих.
char phone[10][20]; // Массив телефонных номеров служащих.
float hours[10]; // Массив часов, отработанных за неделю.
float wage[10]; // Массив окладов.

int menu();
void enter(), report();

int main() {
 	int choice;

   	do {
    	choice = menu();
        switch (choice) {
          case 0:
            break;
          case 1:
            enter();
            break;
          case 2:
            report();
            break;
          default:
            std::cout << "Попробуйте еще раз" << std::endl << std::endl;
        }
    } while (choice != 0);
 	return 0;
}


// Функция возвращает команду, выбранную пользователем:
int menu() {
	int choice;
    std::cout << "0. Выход из программы" << std::endl;
    std::cout << "1. Ввод информации" << std::endl;
    std::cout << "2. Генерирование отчета" << std::endl;
    std::cout << std::endl << "Выберите команду";

    std::cin >> choice;
    return choice;
}

// Функция ввода информации в базу
void enter() {
	int i;
    char temp[80];
    for (i = 0; i < 10; i++) {
  		std::cout << "Введите фамилию: ";
     	std::cin >> name[i];

        std::cout << "Введите номер телефона: ";
        std::cin >> phone[i];

        std::cout << "Введите количество отработанных часов: ";
        std::cin >> hours[i];

        std::cout << "Введите оклад: ";
        std::cin >> wage[i];
    }
}

// Отображение отчета
void report() {
  int i;
  for (i = 0; i < 10; i++) {
	std::cout << name[i] << " " << phone[i] << std::endl;
    std::cout << "Заработная плата за неделю: " << wage[i] * hours[i];
    std::cout << std::endl;
  }
}