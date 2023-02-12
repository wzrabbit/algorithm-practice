#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> colors;
int V, E;

bool check_single_vertex(int start_node) {
    if (colors[start_node] != -1) {
        return true;
    }

    queue<int> que;
    que.push(start_node);
    colors[start_node] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            if (colors[nxt] != -1 && colors[nxt] == colors[cur]) {
                return false;
            }

            if (colors[nxt] == -1) {
                colors[nxt] = 1 - colors[cur];
                que.push(nxt);
            }
        }
    }

    return true;
}

bool is_bipartite_graph() {
    for (int i = 1; i <= V; i++) {
        if (!check_single_vertex(i)) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E;

        graph.clear();
        colors.clear();
        graph.resize(V + 1);
        colors.resize(V + 1);
        fill(colors.begin(), colors.end(), -1);

        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (is_bipartite_graph()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}