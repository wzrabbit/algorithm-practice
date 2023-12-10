#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N <= 3) {
        cout << -1;
        return 0;
    }

    cout << 4 << ' ' << 2 << ' ' << 3 << ' ' << 1 << ' ';

    for (int i = 5; i <= N; i++) {
        cout << i << ' ';
    }
}