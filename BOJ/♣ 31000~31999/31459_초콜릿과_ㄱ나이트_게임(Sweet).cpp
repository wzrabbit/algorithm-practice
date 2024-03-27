#include <algorithm>
#include <iostream>
using namespace std;

bool grid[111][111];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C, MR, MC;
        cin >> R >> C >> MR >> MC;

        fill(&grid[1][1], &grid[R][C + 1], true);
        int answer = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (grid[r][c]) {
                    answer += 1;
                    grid[r + MR][c + MC] = false;
                }
            }
        }

        cout << answer << '\n';
    }
}
