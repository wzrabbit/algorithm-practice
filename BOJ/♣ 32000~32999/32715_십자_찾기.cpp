#include <iostream>
using namespace std;

int grid[2501][2501];
int prefix[2501][2501];
int R, C, K;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] -
                           prefix[r - 1][c - 1] + grid[r][c];
        }
    }

    int answer = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int horizontal =
                prefix[r][min(C, c + K)] - prefix[r][max(0, c - K - 1)] -
                prefix[r - 1][min(C, c + K)] + prefix[r - 1][max(0, c - K - 1)];
            int vertical =
                prefix[min(R, r + K)][c] - prefix[max(0, r - K - 1)][c] -
                prefix[min(R, r + K)][c - 1] + prefix[max(0, r - K - 1)][c - 1];

            if (horizontal == vertical && horizontal == 2 * K + 1) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
