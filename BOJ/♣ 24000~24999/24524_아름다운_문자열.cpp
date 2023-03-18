#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int alphabet_state[26];
int alphabet_index[26];
string S, T;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> S >> T;

    for (int i = 0; i < 26; i++) {
        alphabet_index[i] = -1;
    }

    for (size_t i = 0; i < T.size(); i++) {
        alphabet_index[T[i] - 'a'] = i;
    }

    for (size_t i = 0; i < S.size(); i++) {
        int current_alphabet_index = alphabet_index[S[i] - 'a'];

        if (current_alphabet_index == -1) {
            continue;
        }

        if (current_alphabet_index == 0) {
            alphabet_state[0] += 1;
            continue;
        }

        if (alphabet_state[current_alphabet_index - 1] > 0) {
            alphabet_state[current_alphabet_index - 1] -= 1;
            alphabet_state[current_alphabet_index] += 1;
        }
    }

    cout << alphabet_state[T.size() - 1];
}