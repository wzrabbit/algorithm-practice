#include <iostream>
using namespace std;

char grid[52][52];

int main() {
    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int r_empty_count = 0;
    int c_empty_count = 0;

    for (int r = 1; r <= R; r++) {
        bool is_empty = true;

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'X') {
                is_empty = false;
            }
        }

        if (is_empty) {
            r_empty_count += 1;
        }
    }

    for (int c = 1; c <= C; c++) {
        bool is_empty = true;

        for (int r = 1; r <= R; r++) {
            if (grid[r][c] == 'X') {
                is_empty = false;
            }
        }

        if (is_empty) {
            c_empty_count += 1;
        }
    }

    cout << max(r_empty_count, c_empty_count);
}
