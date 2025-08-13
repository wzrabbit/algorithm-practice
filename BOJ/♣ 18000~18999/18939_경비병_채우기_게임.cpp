#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C, K;
        cin >> R >> C >> K;

        if (C < K * 2) {
            cout << "Yuto\n";
            continue;
        }

        if ((R * C - K * K * 2) % 2 == 0) {
            cout << "Platina\n";
        } else {
            cout << "Yuto\n";
        }
    }
}
