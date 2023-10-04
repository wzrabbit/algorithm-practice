#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dp[30001];
vector<int> start_times[30001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int s, e;
        cin >> s >> e;

        start_times[e].push_back(s);
    }

    for (int i = 1; i <= 30000; i++) {
        dp[i] = dp[i - 1];

        for (size_t j = 0; j < start_times[i].size(); j++) {
            int start_time = start_times[i][j];

            dp[i] = max(dp[i], dp[start_time] + i - start_time);
        }
    }

    cout << dp[30000];
}