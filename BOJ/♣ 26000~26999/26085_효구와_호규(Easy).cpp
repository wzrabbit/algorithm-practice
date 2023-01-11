#include <iostream>
using namespace std;

int grid[1000][1000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    bool success = false;
    int zero_count = 0;
    cin >> R >> C;

    if (R * C % 2 == 1) {
        cout << -1;
        return 0;
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 0) {
                zero_count += 1;
            }
        }
    }

    if (zero_count % 2 == 1) {
        cout << -1;
        return 0;
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C - 1; c++) {
            if (grid[r][c] == grid[r][c + 1]) {
                success = true;
            }
        }
    }

    for (int r = 0; r < R - 1; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == grid[r + 1][c]) {
                success = true;
            }
        }
    }

    if (success) {
        cout << 1;
    } else {
        cout << -1;
    }
}