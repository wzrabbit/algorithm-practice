#include <iostream>
using namespace std;

int grid[2][200001];
int dp[200001];
bool is_prime[200001];
int N, A, B;

void init_prime_array() {
    fill(is_prime + 2, is_prime + 200001, true);

    for (int i = 2; i <= 450; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 200000; j += i) {
            is_prime[j] = false;
        }
    }
}

int get_score(int sum) {
    if (is_prime[sum]) {
        return A;
    }

    return B;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> A >> B;

    init_prime_array();

    for (int r = 0; r < 2; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    dp[1] = get_score(grid[0][1] + grid[1][1]);

    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1] + get_score(grid[0][i] + grid[1][i]),
                    dp[i - 2] + get_score(grid[0][i - 1] + grid[0][i]) +
                        get_score(grid[1][i - 1] + grid[1][i]));
    }

    cout << dp[N];
}
