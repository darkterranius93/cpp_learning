//
// Created by Денис Скрипниченко on 23.04.2025.
//
#include <iostream>
#include <optional>
#include <vector>

#define UNKNOWN_INDEX -1

template <typename DeckItem>
class Deck {
    private:
      DeckItem *items;
      int capacity;
      int startIndex;
      int endIndex;
      void extend();

    public:
      Deck();
      void put_right(DeckItem value);
      void put_left(DeckItem value);
      std::optional<DeckItem> pop_right();
      std::optional<DeckItem> pop_left();
      void print_values();
};


/**
* Расширение хранилища элементов дека
*/
template <typename DeckItem>
void Deck<DeckItem>::extend() {
    DeckItem *oldItems = items;
    int oldStartIndex = startIndex;
    int oldEndIndex = endIndex;
    int oldItemsCount = endIndex - startIndex + 1;

    // Увеличить размер массива элементов
    capacity = capacity + 100;
    // Выделить память под новый массив элементов
    items = new DeckItem[capacity];

    if (oldStartIndex != UNKNOWN_INDEX && oldEndIndex != UNKNOWN_INDEX) {
        int insertIndex = capacity / 2 - oldItemsCount / 2;
        startIndex = insertIndex;
        for (int i = oldStartIndex; i <= oldEndIndex; i++, insertIndex++) {
            items[insertIndex] = oldItems[i];
        }
        endIndex = insertIndex;
    } else {
        startIndex = UNKNOWN_INDEX;
        endIndex = UNKNOWN_INDEX;
    }
}

template <typename DeckItem>
void Deck<DeckItem>::put_right(DeckItem value) {
    if (endIndex == capacity - 1) {
        extend();
    }
    endIndex++;
    items[endIndex] = value;
}

template <typename DeckItem>
void Deck<DeckItem>::put_left(DeckItem value) {
    if (startIndex == 0) {
        extend();
    }
    startIndex--;
    items[startIndex] = value;
}

template <typename DeckItem>
Deck<DeckItem>::Deck() {
    capacity = 100;
    items = new DeckItem[capacity];
    startIndex = UNKNOWN_INDEX;
    endIndex = UNKNOWN_INDEX;

}

template <typename DeckItem>
void Deck<DeckItem>::print_values() {
    for (int i = startIndex; i <= endIndex; i++) {
        std::cout << items[i] << " ";
    }
}


int main() {
    Deck<int> deck;
    deck.put_right(1);
    deck.put_right(2);
    deck.print_values();


    return 0;
}