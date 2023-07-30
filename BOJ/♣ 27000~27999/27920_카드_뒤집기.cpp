#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    cout << "YES\n";

    for (int i = 1; i <= N / 2; i++) {
        cout << N - i * 2 + 1 << ' ';
    }

    cout << N << ' ';

    for (int i = (N - 1) / 2; i >= 1; i--) {
        cout << N - i * 2 << ' ';
    }

    cout << '\n';

    int l = 1;
    int r = N;

    while (l < r) {
        cout << l << ' ' << r << ' ';
        l += 1;
        r -= 1;
    }

    if (N % 2 == 1) {
        cout << l;
    }
}