#include <iostream>
using namespace std;

char canvas[22][22];

int main() {
    int R, C;
    cin >> R >> C;

    int top, left, right, bottom;
    cin >> top >> left >> right >> bottom;

    for (int r = 1 + top; r <= top + R; r++) {
        cin >> (canvas[r] + 1 + left);
    }

    for (int r = 1; r <= 20; r++) {
        for (int c = 1; c <= 20; c++) {
            if (canvas[r][c] != 0) {
                continue;
            }

            if ((r + c) % 2 == 0) {
                canvas[r][c] = '#';
            } else {
                canvas[r][c] = '.';
            }
        }
    }

    for (int r = 1; r <= top + bottom + R; r++) {
        for (int c = 1; c <= left + right + C; c++) {
            cout << canvas[r][c];
        }

        cout << '\n';
    }
}
