#include <algorithm>
#include <iostream>
#define INF 1234567
using namespace std;

int grid[1001][1001];
int prefix[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] -
                           prefix[r - 1][c - 1] + grid[r][c];
        }
    }

    int answer_r = 0;
    int answer_c = 0;
    int score = INF;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == 1) {
                continue;
            }

            int start_r = max(1, r - D);
            int end_r = min(N, r + D);
            int start_c = max(1, c - D);
            int end_c = min(N, c + D);

            int cur_score = prefix[end_r][end_c] - prefix[start_r - 1][end_c] -
                            prefix[end_r][start_c - 1] +
                            prefix[start_r - 1][start_c - 1];

            if (cur_score < score) {
                score = cur_score;
                answer_r = r;
                answer_c = c;
            }
        }
    }

    cout << answer_r << " " << answer_c << '\n';

    if (score >= 1) {
        cout << score << '\n';
    }
}
