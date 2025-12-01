#include <iostream>
using namespace std;

int grid[1001][1001];

void simulate(int r1, int c1, int r2, int c2, int id) {
    if (r1 > r2 || c1 > c2) {
        return;
    }

    int mid_c = (c1 + c2) / 2;
    int current_id = id;

    for (int c = c1; c <= mid_c; c++) {
        grid[r1][c] = current_id;
        grid[r2][c] = current_id;
        current_id += 1;
    }

    int mid_id = current_id;

    current_id = id;

    for (int c = c2; c > mid_c; c--) {
        grid[r1][c] = current_id;
        grid[r2][c] = current_id;
        current_id += 1;
    }

    int mid_r = (r1 + r2) / 2;

    current_id = mid_id;

    for (int r = r1 + 1; r <= mid_r; r++) {
        grid[r][c1] = current_id;
        grid[r][c2] = current_id;
        current_id += 1;
    }

    current_id = mid_id;

    for (int r = r2 - 1; r > mid_r; r--) {
        grid[r][c1] = current_id;
        grid[r][c2] = current_id;
        current_id += 1;
    }

    simulate(r1 + 1, c1 + 1, r2 - 1, c2 - 1, current_id);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    simulate(1, 1, R, C, 1);

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c] << ' ';
        }
        cout << '\n';
    }
}
