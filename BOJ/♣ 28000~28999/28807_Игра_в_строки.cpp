#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int S_state[26];
int T_state[26];
int K;

bool is_possible() {
    int matched = 0;

    for (int i = 0; i < 26; i++) {
        matched += min(S_state[i], T_state[i]);
    }

    return matched == K;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S, T;
    cin >> K >> S >> T;

    for (size_t i = 0; i < T.size(); i++) {
        T_state[T[i] - 'a'] += 1;
    }

    for (int i = 0; i < K; i++) {
        S_state[S[i] - 'a'] += 1;

        if (is_possible()) {
            cout << "YES";
            return 0;
        }
    }

    for (size_t i = 0; i < S.size() - K + 1; i++) {
        S_state[S[i] - 'a'] -= 1;
        S_state[S[i + K] - 'a'] += 1;

        if (is_possible()) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}