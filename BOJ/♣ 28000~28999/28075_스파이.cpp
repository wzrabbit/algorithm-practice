#include <algorithm>
#include <iostream>
using namespace std;

int scores[7];
int dp[9][7][81];  // dp[몇 일차][작업의 종류][누적 진척도] = 경우의 수

int main() {
    int D, M;
    cin >> D >> M;

    for (int i = 1; i <= 6; i++) {
        cin >> scores[i];
        dp[1][i][scores[i]] = 1;
    }

    for (int d = 2; d <= D; d++) {
        for (int r = 1; r <= 6; r++) {
            for (int c = 0; c <= 80; c++) {
                for (int i = 1; i <= 6; i++) {
                    int score = scores[r];

                    if (i == r || abs(i - r) == 3) {
                        score /= 2;
                    }

                    if (c >= score) {
                        dp[d][r][c] += dp[d - 1][i][c - score];
                    }
                }
            }
        }
    }

    int counts = 0;

    for (int r = 1; r <= 6; r++) {
        for (int c = M; c <= 80; c++) {
            counts += dp[D][r][c];
        }
    }

    cout << counts;
}