// Design a deck of cards that can be used for different card game applications.
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const string val[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
const string type[] = {"Spades","Hearts","Clubs","Diamonds"};
const vector<string> FACES(val, val+13);
const vector<string> SUITS(type, type+4);
const int MAX_CARDS = FACES.size()*SUITS.size();
class Card {
private:
    int value;
public:
    Card() {
        value = 0;
    }
    Card(int n) {
        if (n < 0 || n >= MAX_CARDS) {
            cout << "\nInvalid card index, program terminated !" << endl;
        }
        value = n;
    }
    string getFace() {
        return FACES[value % FACES.size()];
    }
    string getSuit() {
        return SUITS[value / FACES.size()];
    }
    string toString() {
        string s = getSuit()[0] + getFace();
        return s;
    }
};

class Deck {
private:
    vector<Card*> cards;
    vector<Card*> drawnCards;
public:
    Deck(int size) {
        for (int i = 0; i < size; i++) {
            cards.push_back(new Card(i));
        }
    }
    void shuffle() {
        int n;
        int i, idx;
        // put all cards from drawnCards to Cards
        for (i = 0; i < drawnCards.size(); i++) {
            cards.push_back(drawnCards[i]);
        }
        drawnCards.clear();

        // shuffle cards
        n = cards.size();
        srand((unsigned int)time(0));
        for (i = 0; i < n; i++) {
            idx = rand()%(n-i)+i;
            swap(cards[i], cards[idx]);
        }
    }
    Card* draw() {
        Card *card;
        if (cards.empty()) {
            shuffle();
        }
        card = cards.back();
        cards.pop_back();
        drawnCards.push_back(card);
        return card;
    }

    void showDeck() {
        int i;
        cout << "Cards:" << endl;
        for (i = 0; i < cards.size(); i++) {
            cout << (*cards[i]).toString() << "  ";
            if (i % 4 == 3) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "DrawnCards:" << endl;
        for (i = 0; i < drawnCards.size(); i++) {
            cout << (*drawnCards[i]).toString() << "  ";
            if (i % 4 == 3) {
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main(void) {
    Deck deck(52);
    Card *card;
    deck.showDeck();
    deck.shuffle();
    deck.showDeck();
    
    for (int i = 0; i < 10; i++) {
        card = deck.draw();
        cout << (*card).toString() << endl;
    }

    deck.showDeck();
    
    return 0;
}
