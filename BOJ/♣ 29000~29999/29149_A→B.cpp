#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (M == 1 && N % 2 == 1) {
        cout << -1;
        return 0;
    }

    cout << M << '\n';

    if (N % 2 == 1) {
        cout << 1 << ' ' << 3 << ' ';

        for (int i = 1; i <= M - 2; i++) {
            cout << N - i * 2 << ' ';
        }
    } else {
        cout << 2 << ' ';

        for (int i = 1; i <= M - 1; i++) {
            cout << N - i * 2 << ' ';
        }
    }
}