#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    string S;

    cin >> N >> S >> Q;

    int up_count = 0;
    int right_count = 0;
    int diag_count = 0;
    int success_count = 0;

    for (size_t i = 0; i < N; i++) {
        if (S[i] == 'U') {
            up_count += 1;
        } else if (S[i] == 'R') {
            right_count += 1;
        } else {
            diag_count += 1;
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;

        if (x > right_count + diag_count + 1 || y > up_count + diag_count + 1) {
            continue;
        }

        int required_diag = max(x - right_count, y - up_count) - 1;

        if (x < required_diag + 1 || y < required_diag + 1) {
            continue;
        }

        success_count += 1;
    }

    cout << success_count;
}