#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 1;
        return 0;
    }

    if (N % 2 == 1) {
        cout << -1;
        return 0;
    }

    int l = 1;
    int r = N;

    for (int i = 1; i <= N / 2; i++) {
        cout << r << ' ' << l << ' ';

        l += 2;
        r -= 2;
    }
}