#include <iostream>
using namespace std;

int grid[301][301];
bool can_cross[301][301];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int C, R;
    cin >> C >> R;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    can_cross[0][1] = true;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 0) {
                continue;
            }

            if (can_cross[r - 1][c] || can_cross[r][c - 1]) {
                can_cross[r][c] = true;
            }
        }
    }

    if (can_cross[R][C]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
