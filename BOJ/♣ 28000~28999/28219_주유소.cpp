#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[200001];
int dp[200001];
bool visited[200001];
int gas_station_count = 0;
int N, K;

void tree_dp(int cur) {
    visited[cur] = true;
    vector<int> next_dps;

    for (size_t i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];

        if (visited[next]) {
            continue;
        }

        tree_dp(next);

        next_dps.push_back(dp[next]);
    }

    sort(next_dps.begin(), next_dps.end(), greater<>());

    if (next_dps.size() >= 2 && next_dps[0] + next_dps[1] + 2 >= K) {
        dp[cur] = -1;
        gas_station_count += 1;
        return;
    }

    if (next_dps.size() >= 1) {
        dp[cur] = next_dps[0] + 1;
    }

    if (dp[cur] >= K) {
        dp[cur] = -1;
        gas_station_count += 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    tree_dp(1);

    cout << gas_station_count;
}
