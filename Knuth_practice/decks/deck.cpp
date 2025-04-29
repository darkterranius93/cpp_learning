//
// Created by Денис Скрипниченко on 23.04.2025.
//
#include <iostream>
#include <optional>
#include <vector>

#define UNKNOWN_INDEX -1
#define DEFAULT_CAPACITY 10

template <typename DeckItem>
class Deck {
    private:
      DeckItem **items;
      int capacity;
      int startIndex; // Индекс начала заполненных элементов
      int endIndex; // Индекс окончания заполненных элементов
      void extend();

    public:
      Deck();
      void put_right(DeckItem value);
      void put_left(DeckItem value);
      std::optional<DeckItem> pop_right();
      std::optional<DeckItem> pop_left();
      bool isEmpty() { return startIndex == UNKNOWN_INDEX && endIndex == UNKNOWN_INDEX; };
      void print_values();
};


/**
* Расширение хранилища элементов дека
*/
template <typename DeckItem>
void Deck<DeckItem>::extend() {
    DeckItem **oldItems = items;
    int oldStartIndex = startIndex;
    int oldEndIndex = endIndex;
    int oldItemsCount = endIndex - startIndex + 1;
    // Увеличить размер массива элементов
    capacity = capacity + DEFAULT_CAPACITY;
    // Выделить память под новый массив элементов
    items = new DeckItem*[capacity];
    for (int i = 0; i < capacity; i++) {
        items[i] = NULL;
    }

    if (oldStartIndex != UNKNOWN_INDEX && oldEndIndex != UNKNOWN_INDEX) {
        // Ищем начало вставки старого массива по центру нового
        int insertIndex = capacity / 2 - oldItemsCount / 2 - 1;
        startIndex = insertIndex;
        for (int i = oldStartIndex; i <= oldEndIndex; i++, insertIndex++) {
            items[insertIndex] = oldItems[i];
        }
        endIndex = insertIndex-1;
    } else {
        startIndex = UNKNOWN_INDEX;
        endIndex = UNKNOWN_INDEX;
    }
}

template <typename DeckItem>
void Deck<DeckItem>::put_right(DeckItem value) {
    // Если справа нет места - расширяем память
    if (endIndex == capacity - 1) {
        extend();
    }

    int insertIndex;
    // Если массив пустой - определяем начальную позицию вставки
    if (endIndex == UNKNOWN_INDEX && startIndex == UNKNOWN_INDEX) {
        startIndex = endIndex = capacity / 2;
        insertIndex = startIndex;
    } else {
        insertIndex = endIndex + 1;
        endIndex = endIndex + 1;
    }

    items[insertIndex] = new int(value);
}

template <typename DeckItem>
void Deck<DeckItem>::put_left(DeckItem value) {
    // Если слева нет места - расширяем память
    if (startIndex == 0 && items[0] != NULL) {
        extend();
    }

    int insertIndex;
    // Если массив пустой - определяем начальную позицию вставки
    if (endIndex == UNKNOWN_INDEX && startIndex == UNKNOWN_INDEX) {
        startIndex = endIndex = capacity / 2;
        insertIndex = startIndex;
    } else {
        insertIndex = startIndex - 1;
        startIndex = startIndex - 1;
    }
    items[startIndex] = new int(value);
}

template <typename DeckItem>
Deck<DeckItem>::Deck() {
    capacity = DEFAULT_CAPACITY;
    items = new DeckItem*[capacity];
    startIndex = UNKNOWN_INDEX;
    endIndex = UNKNOWN_INDEX;

}

template <typename DeckItem>
void Deck<DeckItem>::print_values() {
//    int from = startIndex == UNKNOWN_INDEX ? 0 : startIndex;
//    int to = endIndex == UNKNOWN_INDEX ? capacity-1 : endIndex;

    int from = 0;
    int to = capacity - 1;
    for (int i = from; i <= to; i++) {
        if (items[i] != NULL) {
            std::cout << *items[i] << " ";
        } else {
            std::cout << "null" << " ";
        }
    }
    std::cout << std::endl;
}
