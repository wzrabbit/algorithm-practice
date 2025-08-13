#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll cost[100001];
vector<int> graph[100001];
ll dp[100001][2];
bool visited[100001];

void dfs(int cur) {
    visited[cur] = true;

    vector<ll> candidates;
    dp[cur][0] = cost[cur] * 2;
    dp[cur][1] = cost[cur];

    for (int nxt : graph[cur]) {
        if (visited[nxt]) {
            continue;
        }

        dfs(nxt);
        candidates.push_back(dp[nxt][1]);
        dp[cur][0] += dp[nxt][0];
        dp[cur][1] += dp[nxt][1];
    }

    sort(candidates.begin(), candidates.end());

    if (cur != 1) {
        for (int i = 0; i < int(candidates.size()) - 1; i++) {
            dp[cur][0] += candidates[i] * 2;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
    cost[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << dp[1][0];
}
