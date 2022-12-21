#include <iostream>
using namespace std;

char grid[401][401];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;
        int candy = 0;
        cin >> R >> C;

        for (int r = 0; r < R; r++) {
            cin >> grid[r];
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C - 2; c++) {
                if (grid[r][c] == '>' && grid[r][c + 1] == 'o' && grid[r][c + 2] == '<') {
                    candy += 1;
                }
            }
        }

        for (int r = 0; r < R - 2; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 'v' && grid[r + 1][c] == 'o' && grid[r + 2][c] == '^') {
                    candy += 1;
                }
            }
        }

        cout << candy << '\n';
    }
}