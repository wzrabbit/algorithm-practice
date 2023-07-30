#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    if (R == 1 && C == 1) {
        cout << "1\n1";

        return 0;
    }

    if (R == 1) {
        cout << "2\n";

        for (int c = 1; c <= C; c++) {
            cout << c % 2 + 1 << ' ';
        }

        return 0;
    }

    if (C == 1) {
        cout << "2\n";

        for (int r = 1; r <= R; r++) {
            cout << r % 2 + 1 << '\n';
        }

        return 0;
    }

    cout << "4\n";

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (r % 2 == 1) {
                cout << 1 + c % 2 << ' ';
            } else {
                cout << 3 + c % 2 << ' ';
            }
        }

        cout << '\n';
    }
}