#include <iostream>
#include <string>
using namespace std;

bool check(int cur, string& S) {
    for (int i = cur; i < S.size(); i++) {
        if (S[cur] < S[i]) {
            return true;
        } else if (S[cur] > S[i]) {
            return false;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string S;
        cin >> S;

        cout << "Case #" << t << ": ";

        for (size_t i = 0; i < S.size() - 1; i++) {
            if (S[i] < S[i + 1] || (S[i] == S[i + 1] && check(i, S))) {
                cout << S[i] << S[i];
            } else {
                cout << S[i];
            }
        }

        cout << S[S.size() - 1] << '\n';
    }
}