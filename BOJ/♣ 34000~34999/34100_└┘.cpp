#include <iostream>
using namespace std;

char grid[3002][3002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;

        for (int r = 1; r <= R; r++) {
            cin >> (grid[r] + 1);
        }

        for (int r = R; r >= 2; r--) {
            for (int c = 1; c <= C - 1; c++) {
                if (c <= C - 2 && grid[r][c] == '.' && grid[r][c + 1] == 'a' && grid[r][c + 2] == '.' && grid[r - 1][c] == '.') {
                    grid[r][c] = 'a';
                    grid[r][c + 1] = 'a';
                    grid[r - 1][c] = 'a';
                    grid[r][c + 2] = 'b';
                    grid[r + 1][c + 1] = 'b';
                    grid[r + 1][c + 2] = 'b';
                    continue;
                }

                if (c <= C - 2 && grid[r][c] == '.' && grid[r][c + 1] == 'a' && grid[r][c + 2] == '.' && grid[r - 1][c + 1] == '.') {
                    grid[r][c] = 'b';
                    grid[r][c + 1] = 'b';
                    grid[r - 1][c + 1] = 'b';
                    grid[r][c + 2] = 'b';
                    grid[r + 1][c + 1] = 'b';
                    grid[r + 1][c + 2] = 'b';
                    continue;
                }

                if (grid[r][c] != '.' || grid[r][c + 1] != '.') {
                    continue;
                }

                if (grid[r - 1][c] == '.') {
                    grid[r][c] = 'a';
                    grid[r][c + 1] = 'a';
                    grid[r - 1][c] = 'a';
                    continue;
                }

                if (grid[r - 1][c + 1] == '.') {
                    grid[r][c] = 'b';
                    grid[r][c + 1] = 'b';
                    grid[r - 1][c + 1] = 'b';
                }
            }
        }

        bool success = true;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (grid[r][c] == '.') {
                    success = false;
                }
            }
        }

        if (success) {
            for (int r = 1; r <= R; r++) {
                for (int c = 1; c <= C; c++) {
                    cout << grid[r][c];
                }
                cout << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
}
