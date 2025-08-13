#include <iostream>
using namespace std;

int grid[501][501];

int main() {
    int R, C;
    cin >> R >> C;

    if (R % 2 == 1 && C % 2 == 1) {
        cout << "No";
        return 0;
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    if (C % 2 == 0) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c += 2) {
                swap(grid[r][c], grid[r][c + 1]);
            }
        }
    } else {
        for (int r = 1; r <= R; r += 2) {
            for (int c = 1; c <= C; c++) {
                swap(grid[r][c], grid[r + 1][c]);
            }
        }
    }

    cout << "Yes\n";

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c] << ' ';
        }
        cout << "\n";
    }
}
