#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
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

    int T;
    cin >> T;

    while (T--) {
        int V;
        cin >> V;

        tree.clear();
        tree.resize(V + 1);
        fill(visited + 1, visited + V + 1, false);
        fill(parent + 1, parent + V + 1, false);
        fill(level + 1, level + V + 1, false);

        for (int i = 1; i < V; i++) {
            int A, B;
            cin >> A >> B;
            tree[A].push_back(B);
            tree[B].push_back(A);
            parent[B] = A;
        }

        int root = 0;
        for (int i = 1; i <= V; i++) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }

        dfs(root, 0);

        int node_x, node_y;
        cin >> node_x >> node_y;
        cout << get_lca(node_x, node_y) << '\n';
    }
}