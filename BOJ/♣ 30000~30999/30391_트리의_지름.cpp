#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 2; i <= min(K + 1, N); i++) {
        cout << 1 << ' ' << i << '\n';
    }

    for (int i = 1; i <= N - K - 1; i++) {
        cout << (i - 1) / (K - 1) + 2 << ' ' << K + i + 1 << '\n';
    }
}