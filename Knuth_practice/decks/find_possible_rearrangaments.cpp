//
// Created by Денис Скрипниченко on 29.04.2025.
//
#import "deck.cpp"

template <typename ArrayItem>
class DeckRearranging {
    //Deck<ArrayItem> deck;

    public:
      void findUniqueRearrangings(ArrayItem *items);
};

template <typename ArrayItem>
void DeckRearranging<ArrayItem>::findUniqueRearrangings(ArrayItem *items) {

}

int main() {
    Deck<int> deck;
    deck.put_right(0);
    deck.put_right(0);
    deck.put_right(0);
    deck.put_right(0);
    deck.put_right(0);
    deck.put_right(0);
    deck.print_values();
    deck.put_left(7);
    deck.put_left(6);
    deck.put_left(5);
    deck.put_left(4);
    deck.put_left(3);
    deck.put_left(2);
    deck.put_left(1);
    deck.put_left(0);

    deck.print_values();

    return 0;
}