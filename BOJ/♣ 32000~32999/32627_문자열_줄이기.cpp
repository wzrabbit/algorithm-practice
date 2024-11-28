#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < N; j++) {
            if (S[j] == 'a' + i) {
                S[j] = '.';
                M -= 1;
            }

            if (M == 0) {
                break;
            }
        }

        if (M == 0) {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        if (S[i] != '.') {
            cout << S[i];
        }
    }
}
