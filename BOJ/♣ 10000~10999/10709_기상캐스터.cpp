#include <algorithm>
#include <iostream>
using namespace std;

char grid[102][102];
int state[102][102];
int R, C;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    fill(&state[1][1], &state[R][C + 1], -1);

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'c') {
                for (int i = c; i <= C; i++) {
                    state[r][i] = i - c;
                }
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << state[r][c] << ' ';
        }
        cout << '\n';
    }
}