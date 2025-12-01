#include <iostream>
using namespace std;

int grid[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int answer = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            bool greater = true;

            for (int i = 0; i < 4; i++) {
                int adj_r = r + dr[i];
                int adj_c = c + dc[i];

                if (adj_r < 1 || adj_r > R || adj_c < 1 || adj_c > C) {
                    continue;
                }

                if (grid[r][c] <= grid[adj_r][adj_c]) {
                    greater = false;
                    break;
                }
            }

            if (greater) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
