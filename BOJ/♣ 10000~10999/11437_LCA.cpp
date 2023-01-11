#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50001];
bool visited[50001];
int parent[50001];
int level[50001];

void dfs(int cur_node, int cur_level) {
    visited[cur_node] = true;

    for (size_t i = 0; i < tree[cur_node].size(); i++) {
        int next_node = tree[cur_node][i];
        if (visited[next_node]) continue;

        parent[next_node] = cur_node;
        level[next_node] = cur_level + 1;
        dfs(next_node, cur_level + 1);
    }
}

int get_lca(int x, int y) {
    while (x != y) {
        if (level[x] >= level[y]) {
            x = parent[x];
        } else {
            y = parent[y];
        }
    }

    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V;
    cin >> V;

    for (int i = 1; i < V; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);

    int Q;
    cin >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;
        cout << get_lca(x, y) << '\n';
    }
}