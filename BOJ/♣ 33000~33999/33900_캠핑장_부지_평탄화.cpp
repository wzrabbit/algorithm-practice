#include <iostream>
#define INF 1234
using namespace std;

int grid[1001][1001];
int plan[10][10];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, R, C;
    cin >> N >> M >> R >> C;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> plan[r][c];
        }
    }

    int answer = 0;

    for (int i = 1; i <= N - R + 1; i++) {
        for (int j = 1; j <= M - C + 1; j++) {
            int gap;
            bool success = true;

            for (int r = i; r < i + R; r++) {
                for (int c = j; c < j + C; c++) {
                    if (r == i && c == j) {
                        gap = plan[r - i + 1][c - j + 1] - grid[r][c];
                        continue;
                    }

                    if (plan[r - i + 1][c - j + 1] - grid[r][c] != gap) {
                        success = false;
                    }
                }
            }

            if (success) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
