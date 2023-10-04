#include <iostream>
using namespace std;

char board[102][102];

void flip(int last_r, int last_c) {
    for (int r = 1; r <= last_r; r++) {
        for (int c = 1; c <= last_c; c++) {
            if (board[r][c] == '1') {
                board[r][c] = '0';
            } else {
                board[r][c] = '1';
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    int flip_count = 0;

    for (int r = 1; r <= R; r++) {
        cin >> (board[r] + 1);
    }

    for (int r = R; r >= 1; r--) {
        for (int c = C; c >= 1; c--) {
            if (board[r][c] == '1') {
                flip(r, c);
                flip_count += 1;
            }
        }
    }

    cout << flip_count;
}