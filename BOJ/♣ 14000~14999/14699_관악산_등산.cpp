#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[5001];
int height[5001];
int dp[5001];

int top_down(int cur) {
    int best = 0;

    if (dp[cur] > 0) {
        return dp[cur];
    }

    for (size_t i = 0; i < graph[cur].size(); i++) {
        best = max(top_down(graph[cur][i]), best);
    }

    return dp[cur] = best + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        cin >> height[i];
    }

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        if (height[u] > height[v]) {
            graph[v].push_back(u);
        } else if (height[u] < height[v]) {
            graph[u].push_back(v);
        }
    }

    for (int i = 1; i <= V; i++) {
        cout << top_down(i) << '\n';
    }
}