#include <iostream>
#include <string>
using namespace std;

char state[53];
string S;
int Q;

void init() {
    for (int i = 0; i < 26; i++) {
        state[i] = 'A' + i;
    }

    for (int i = 26; i < 52; i++) {
        state[i] = 'a' + i - 26;
    }
}

int char_to_index(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        return letter - 'A';
    } else {
        return letter - 'a' + 26;
    }
}

void perform_query1() {
    char before, after;
    cin >> before >> after;

    for (int i = 0; i < 52; i++) {
        if (state[i] == before) {
            state[i] = after;
        }
    }
}

void perform_query2() {
    for (size_t i = 0; i < S.size(); i++) {
        cout << state[char_to_index(S[i])];
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> Q;

    init();

    while (Q--) {
        int query;
        cin >> query;

        if (query == 1) {
            perform_query1();
        } else {
            perform_query2();
        }
    }
}