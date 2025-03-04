#include <algorithm>
#include <iostream>
#define INF 1'000'000'000
using namespace std;

int grid[501][501];
int prefix[501][501];
int zero_prefix[501][501];
int plans[100001];
int plans_prefix[100001];
int sum[250001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    fill(sum, sum + N * N + 1, -INF);

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
            prefix[r][c] = grid[r][c] + prefix[r - 1][c] + prefix[r][c - 1] -
                           prefix[r - 1][c - 1];
            zero_prefix[r][c] = (grid[r][c] == 0 ? 1 : 0) +
                                zero_prefix[r - 1][c] + zero_prefix[r][c - 1] -
                                zero_prefix[r - 1][c - 1];
        }
    }

    int K;
    cin >> K;

    for (int i = 1; i <= K; i++) {
        cin >> plans[i];
    }

    sort(plans + 1, plans + K + 1, greater<int>());

    for (int i = 1; i <= K; i++) {
        plans_prefix[i] = plans_prefix[i - 1] + plans[i];
    }

    for (int r1 = 1; r1 <= N; r1++) {
        for (int c1 = 1; c1 <= N; c1++) {
            for (int s = 1; s <= N - max(r1, c1) + 1; s++) {
                int r2 = r1 + s - 1;
                int c2 = c1 + s - 1;

                int cur_sum = prefix[r2][c2] - prefix[r1 - 1][c2] -
                              prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
                int zero_count = zero_prefix[r2][c2] - zero_prefix[r1 - 1][c2] -
                                 zero_prefix[r2][c1 - 1] +
                                 zero_prefix[r1 - 1][c1 - 1];

                sum[zero_count] = max(sum[zero_count], cur_sum);
            }
        }
    }

    int max_sum = 0;

    for (int i = 0; i <= min(N * N, K); i++) {
        max_sum = max(max_sum, sum[i] + plans_prefix[i]);
    }

    cout << max_sum;
}
