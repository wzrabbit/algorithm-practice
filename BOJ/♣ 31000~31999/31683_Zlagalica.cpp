#include <algorithm>
#include <iostream>
#define INF 999
using namespace std;

struct Block {
    char b;
    int r, c, u, d;
};

char canvas[252][252];
Block blocks[21];
int sequence[21];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= 250; r++) {
        for (int c = 1; c <= 250; c++) {
            canvas[r][c] = '.';
        }
    }

    int pos_r = 250;
    int pos_c = 1;

    for (int i = 1; i <= N; i++) {
        cin >> blocks[i].b >>
            blocks[i].r >>
            blocks[i].c >>
            blocks[i].u >>
            blocks[i].d;
    }

    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
    }

    for (int i = 1; i <= N; i++) {
        Block block = blocks[sequence[i]];

        for (int r = pos_r; r >= pos_r - block.r + 1; r--) {
            for (int c = pos_c; c <= pos_c + block.c - 1; c++) {
                canvas[r][c] = block.b;
            }
        }

        if (block.u == 0) {
            pos_r -= block.r;
            pos_c += block.d - 1;
        } else {
            pos_r -= block.r - block.d;
            pos_c += block.c;
        }
    }

    int start_r = INF;
    int start_c = INF;
    int end_r = -INF;
    int end_c = -INF;

    for (int r = 1; r <= 250; r++) {
        bool is_empty = true;

        for (int c = 1; c <= 250; c++) {
            if (canvas[r][c] != '.') {
                is_empty = false;
                break;
            }
        }

        if (!is_empty) {
            start_r = min(start_r, r);
            end_r = r;
        }
    }

    for (int c = 1; c <= 250; c++) {
        bool is_empty = true;

        for (int r = 1; r <= 250; r++) {
            if (canvas[r][c] != '.') {
                is_empty = false;
                break;
            }
        }

        if (!is_empty) {
            start_c = min(start_c, c);
            end_c = c;
        }
    }

    cout << end_r - start_r + 1 << ' ' << end_c - start_c + 1 << '\n';

    for (int r = start_r; r <= end_r; r++) {
        for (int c = start_c; c <= end_c; c++) {
            cout << canvas[r][c];
        }

        cout << '\n';
    }
}
