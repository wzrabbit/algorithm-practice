#include <iostream>
using namespace std;

char grid[102][102];

int main() {
    int R, C, N;
    cin >> R >> C >> N;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            grid[r][c] = '.';
        }
    }

    int r_area_count = 0;
    int c_area_count = 0;
    bool success = false;

    for (int r = 1; r <= R - (R / 2); r++) {
        int c = N / r;

        if (r * c == N && c <= C - (C / 2)) {
            r_area_count = r;
            c_area_count = c;
            success = true;
            break;
        }
    }

    if (!success) {
        cout << "Impossible";
        return 0;
    }

    for (int r = 2; r < r_area_count * 2; r += 2) {
        for (int c = 1; c <= C; c++) {
            grid[r][c] = '#';
        }
    }

    for (int c = 2; c < c_area_count * 2; c += 2) {
        for (int r = 1; r <= R; r++) {
            grid[r][c] = '#';
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c];
        }

        cout << '\n';
    }
}
