#include <algorithm>
#include <iostream>
#include <vector>
#define INF 999
using namespace std;

int ducks[501];
int dp[501][50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> ducks[i];
    }

    fill(&dp[0][0], &dp[500][50001], INF);
    dp[0][0] = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 0; c <= 50000; c++) {
            dp[r][c] = dp[r - 1][c];

            if (c >= ducks[r]) {
                dp[r][c] = min(dp[r][c], dp[r - 1][c - ducks[r]] + 1);
            }
        }
    }

    vector<int> answers;

    for (int c = 1; c <= 50000; c++) {
        if (dp[N][c] <= K) {
            answers.push_back(c);
        }
    }

    cout << answers.size() << '\n';

    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i] << ' ';
    }
}