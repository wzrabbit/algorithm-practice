#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;

// dp[i번째 칸까지 건넜을 때][큰 선인장 등장여부][연속 선인장 개수][현재 장애물의 종류] = 가짓수
ll dp[1001][2][3][3];

int main() {
    int N;
    cin >> N;

    dp[1][0][0][0] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    dp[i][j][0][0] = (dp[i][j][0][0] + dp[i - 1][j][k][l]) % MOD;
                }
            }
        }

        for (int j = 0; j < 2; j++) {
            dp[i][j][1][1] = (dp[i][j][1][1] + dp[i - 1][j][0][0]) % MOD;
            dp[i][j][2][1] = (dp[i][j][2][1] + dp[i - 1][j][1][1] + dp[i - 1][j][1][2]) % MOD;
            dp[i][1][1][2] = (dp[i][1][1][2] + dp[i - 1][j][0][0]) % MOD;
            dp[i][1][2][2] = (dp[i][1][2][2] + dp[i - 1][j][1][1]) % MOD;
        }
    }

    ll answer = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            answer = (answer + dp[N][1][j][k]) % MOD;
        }
    }

    cout << answer;
}