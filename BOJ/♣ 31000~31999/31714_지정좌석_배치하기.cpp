#include <algorithm>
#include <iostream>
using namespace std;

int grid[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, D;
    cin >> R >> C >> D;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        sort(grid[r] + 1, grid[r] + C + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            grid[r][c] += (r - 1) * D;
        }
    }

    bool success = true;

    for (int c = 1; c <= C; c++) {
        for (int r = 1; r <= R - 1; r++) {
            if (grid[r][c] >= grid[r + 1][c]) {
                success = false;
            }
        }
    }

    if (success) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
