#include <iostream>
#define MOD 1'000'000'009
using namespace std;

int dp[4][100001];

void make_dp_table() {
    dp[1][1] = dp[1][3] = dp[2][2] = dp[2][3] = dp[3][3] = 1;

    for (int i = 4; i <= 100000; i++) {
        dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % MOD;
        dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % MOD;
        dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % MOD;
    }
}

int get_answer(int N) {
    int answer = 0;

    for (int i = 1; i <= 3; i++) {
        answer = (answer + dp[i][N]) % MOD;
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    make_dp_table();

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << get_answer(N) << '\n';
    }
}
