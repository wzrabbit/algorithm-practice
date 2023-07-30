#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
bool is_cycle = false;
bool not_moved = true;

void dfs(int cur) {
    if (cur == 1 && visited[1]) {
        is_cycle = true;
    }

    if (visited[cur]) {
        return;
    }

    visited[cur] = true;

    for (size_t i = 0; i < graph[cur].size(); i++) {
        int next_node = graph[cur][i];
        not_moved = false;
        dfs(next_node);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[v].push_back(u);
    }

    dfs(1);

    cout << is_cycle || not_moved;

    for (int i = 2; i <= V; i++) {
        cout << visited[i];
    }
}