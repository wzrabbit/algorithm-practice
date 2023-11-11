#include <iostream>
using namespace std;

int grid[2001][2001];
int h_prefix[2001][2001];
int f_prefix[2001][2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, Q;
    cin >> R >> C >> Q;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int c = 1; c <= C; c++) {
        for (int r = 1; r <= R; r++) {
            h_prefix[r][c] = h_prefix[r - 1][c] + grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            f_prefix[r][c] = f_prefix[r - 1][c - 1] + h_prefix[r][c];
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        cout << f_prefix[r][c] << '\n';
    }
}
