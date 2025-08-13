#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        if (K != 1) {
            for (int i = 1; i <= N; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }

        if (N <= 3) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = N / 2 + 1; i <= N / 2 * 2; i++) {
            cout << i << ' ' << i - N / 2 << ' ';
        }

        if (N % 2 == 1) {
            cout << N;
        }

        cout << '\n';
    }
}
