#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int diff[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S, T;
    cin >> S >> T;

    for (size_t i = 0; i < S.size(); i++) {
        diff[S[i] - 'a'] += 1;
    }

    for (size_t i = 0; i < T.size(); i++) {
        diff[T[i] - 'a'] -= 1;
    }

    int total_diff = 0;

    for (int i = 0; i < 26; i++) {
        total_diff += abs(diff[i]);
    }

    cout << total_diff;
}
