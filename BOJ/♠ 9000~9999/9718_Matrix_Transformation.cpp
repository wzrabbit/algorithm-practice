#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;

        int sum = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                int cur;
                cin >> cur;

                if ((r + c) % 2 == 0) {
                    sum += cur;
                } else {
                    sum -= cur;
                }
            }
        }

        if (sum == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}