#include <iostream>
#define MOD 1'000'000'007
using namespace std;

char grid[2002][2002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int answer = 1;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            bool success = true;

            for (int i = 0; i < 4; i++) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if (next_r < 1 || next_r > R || next_c < 1 || next_c > C) {
                    continue;
                }

                if (grid[r][c] != grid[next_r][next_c]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                answer = (answer * 2) % MOD;
            }
        }
    }

    cout << answer;
}