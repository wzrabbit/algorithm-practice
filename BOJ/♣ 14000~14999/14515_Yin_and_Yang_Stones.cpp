#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int white_count = 0;
    int black_count = 0;

    string S;
    cin >> S;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'W') {
            white_count += 1;
        } else {
            black_count += 1;
        }
    }

    if (white_count == black_count) {
        cout << 1;
    } else {
        cout << 0;
    }
}