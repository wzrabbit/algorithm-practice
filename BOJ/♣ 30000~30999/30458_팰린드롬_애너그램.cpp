#include <iostream>
#include <string>
using namespace std;

int counts[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string S;

    cin >> N >> S;

    for (size_t i = 0; i < S.size(); i++) {
        if (N % 2 == 1 && i == N / 2) {
            continue;
        }

        counts[S[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] % 2 == 1) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
