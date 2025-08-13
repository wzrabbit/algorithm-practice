#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if ((r + c) % 2 == 0) {
                continue;
            }

            cout << "? " << r << ' ' << c << endl;

            bool success;
            cin >> success;

            if (success) {
                return 0;
            }
        }
    }
}
