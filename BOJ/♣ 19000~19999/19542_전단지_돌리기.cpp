#include <iostream>
#include <vector>
using namespace std;

int dp[100001];
vector<int> graph[100001];
bool visited[100001];

int tree_dp(int cur) {
    visited[cur] = true;

    for (size_t i = 0; i < graph[cur].size(); i++) {
        int next_node = graph[cur][i];

        if (!visited[next_node]) {
            dp[cur] = max(dp[cur], tree_dp(next_node));
        }
    }

    dp[cur] += 1;

    return dp[cur];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S, D;
    cin >> N >> S >> D;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    tree_dp(S);

    int distance = 0;

    for (int i = 1; i <= N; i++) {
        if (dp[i] > D && i != S) {
            distance += 2;
        }
    }

    cout << distance;
}