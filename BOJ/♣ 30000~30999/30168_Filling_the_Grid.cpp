#include <iostream>
#define MOD 1'000'000'007
using namespace std;

int grid[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    int answer = 1;

    for (int r = 1; r <= R; r++) {
        int cur;
        cin >> cur;

        for (int c = 1; c <= cur; c++) {
            grid[r][c] |= 1;
        }

        if (cur < C) {
            grid[r][cur + 1] |= 2;
        }
    }

    for (int c = 1; c <= C; c++) {
        int cur;
        cin >> cur;

        for (int r = 1; r <= cur; r++) {
            grid[r][c] |= 1;
        }

        if (cur < R) {
            grid[cur + 1][c] |= 2;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 3) {
                cout << 0;
                return 0;
            }

            if (grid[r][c] == 0) {
                answer = (answer * 2) % MOD;
            }
        }
    }

    cout << answer;
}