#include <iostream>
using namespace std;

string grid[501][501];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    int total_nine_count = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];

            for (size_t i = 0; i < grid[r][c].size(); i++) {
                if (grid[r][c][i] == '9') {
                    total_nine_count += 1;
                }
            }
        }
    }

    int best_nine_count = 0;

    for (int r = 1; r <= R; r++) {
        int cur_nine_count = 0;

        for (int c = 1; c <= C; c++) {
            for (size_t i = 0; i < grid[r][c].size(); i++) {
                if (grid[r][c][i] == '9') {
                    cur_nine_count += 1;
                }
            }
        }

        best_nine_count = max(cur_nine_count, best_nine_count);
    }

    for (int c = 1; c <= C; c++) {
        int cur_nine_count = 0;

        for (int r = 1; r <= R; r++) {
            for (size_t i = 0; i < grid[r][c].size(); i++) {
                if (grid[r][c][i] == '9') {
                    cur_nine_count += 1;
                }
            }
        }

        best_nine_count = max(cur_nine_count, best_nine_count);
    }

    cout << total_nine_count - best_nine_count;
}