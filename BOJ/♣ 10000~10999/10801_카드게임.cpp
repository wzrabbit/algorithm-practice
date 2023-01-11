#include <iostream>
using namespace std;

int a_cards[10];
int b_cards[10];

int main() {
    int a_score = 0;
    int b_score = 0;

    for (int i = 0; i < 10; i++) {
        cin >> a_cards[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> b_cards[i];

        if (a_cards[i] > b_cards[i]) {
            a_score += 1;
        } else if (a_cards[i] < b_cards[i]) {
            b_score += 1;
        }
    }

    if (a_score > b_score) {
        cout << 'A';
    } else if (a_score < b_score) {
        cout << 'B';
    } else {
        cout << 'D';
    }
}