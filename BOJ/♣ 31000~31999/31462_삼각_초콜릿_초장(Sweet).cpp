#include <algorithm>
#include <iostream>
using namespace std;

char grid[5010][5010];
bool deleted[5010][5010];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    for (int c = 1; c <= N + 1; c++) {
        grid[N + 1][c] = 'X';
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= r; c++) {
            if (deleted[r][c]) {
                continue;
            }

            if (grid[r][c] == 'R') {
                if (
                    grid[r + 1][c] == 'R' &&
                    !deleted[r + 1][c] &&
                    grid[r + 1][c + 1] == 'R' &&
                    !deleted[r + 1][c + 1]) {
                    deleted[r][c] = true;
                    deleted[r + 1][c] = true;
                    deleted[r + 1][c + 1] = true;
                    continue;
                }
            }

            if (grid[r][c] == 'B') {
                if (
                    grid[r][c + 1] == 'B' &&
                    !deleted[r][c + 1] &&
                    grid[r + 1][c + 1] == 'B' &&
                    !deleted[r + 1][c + 1]) {
                    deleted[r][c] = true;
                    deleted[r][c + 1] = true;
                    deleted[r + 1][c + 1] = true;
                    continue;
                }
            }

            cout << 0;
            return 0;
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= r; c++) {
            if (!deleted[r][c]) {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1;
}