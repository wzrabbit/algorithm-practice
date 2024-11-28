#include <iostream>
using namespace std;

int dp[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        dp[cur] = dp[cur - 1] + 1;
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << N - answer;
}
