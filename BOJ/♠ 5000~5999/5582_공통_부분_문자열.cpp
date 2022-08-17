#include <algorithm>
#include <iostream>
using namespace std;

int dp[4001][4001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str_A, str_B;
    cin >> str_A >> str_B;
    int answer = 0;

    for (size_t a = 0; a < str_A.size(); a++) {
        for (size_t b = 0; b < str_B.size(); b++) {
            if (str_A[a] == str_B[b]) {
                dp[a][b] = 1;

                if (a > 0 && b > 0)
                    dp[a][b] += dp[a - 1][b - 1];
            }

            answer = max(answer, dp[a][b]);
        }
    }

    cout << answer;
}