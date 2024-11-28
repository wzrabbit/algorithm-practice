#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int dp[100001][2];
bool visited[100001];
bool sick[100001];
int N, K;

void dfs(int cur) {
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = sick[cur];
    vector<int> vec;

    for (int nxt : graph[cur]) {
        if (visited[nxt]) {
            continue;
        }

        dfs(nxt);
        dp[cur][0] += dp[nxt][0];
        vec.push_back(dp[nxt][1]);
    }

    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < vec.size(); i++) {
        if (dp[cur][1] + vec[i] <= K) {
            dp[cur][1] += vec[i];
        } else {
            dp[cur][0] += 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> sick[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << dp[1][0];
}
