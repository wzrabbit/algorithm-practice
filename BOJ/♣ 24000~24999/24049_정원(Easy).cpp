#include <iostream>
using namespace std;

int grid[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> grid[r][0];
    }

    for (int c = 1; c <= C; c++) {
        cin >> grid[0][c];
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            grid[r][c] = grid[r - 1][c] ^ grid[r][c - 1];
        }
    }

    cout << grid[R][C];
}