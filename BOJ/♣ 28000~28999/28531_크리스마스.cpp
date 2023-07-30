#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    cout << N << '\n';

    int cur = 1;
    int state = 1;

    if (N % 3 == 2) {
        cout << 1 << ' ';
        cur = 2;
        N -= 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << cur << ' ';

        if (state == 2) {
            cur -= 1;
        } else {
            cur += 2;
        }

        state = (state + 1) % 3;
    }

    cout << 1 << ' ';
}