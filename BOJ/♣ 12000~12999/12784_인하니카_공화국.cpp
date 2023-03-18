#include <algorithm>
#include <iostream>
#include <vector>
#define INF 100'000
using namespace std;

struct Node {
    int no, cost;
};

vector<vector<Node>> graph;
vector<bool> visited;
vector<int> dp;

void dfs(int cur) {
    visited[cur] = true;

    if (graph[cur].size() == 1 && cur != 1) {
        dp[cur] = INF;
        return;
    }

    dp[cur] = 0;

    for (size_t i = 0; i < graph[cur].size(); i++) {
        Node next = graph[cur][i];

        if (visited[next.no]) {
            continue;
        }

        dfs(next.no);
        dp[cur] += min(dp[next.no], next.cost);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int V, E;
        cin >> V >> E;

        graph.clear();
        visited.clear();
        dp.clear();
        graph.resize(V + 1);
        visited.resize(V + 1);
        dp.resize(V + 1);

        for (int i = 1; i <= E; i++) {
            int s, e, d;
            cin >> s >> e >> d;

            graph[s].push_back({e, d});
            graph[e].push_back({s, d});
        }

        dfs(1);

        if (V == 1) {
            cout << "0\n";
        } else {
            cout << dp[1] << '\n';
        }
    }
}