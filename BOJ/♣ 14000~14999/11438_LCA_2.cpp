#include <algorithm>
#include <iostream>
#include <vector>
#define LOG 17
using namespace std;

vector<int> tree[100001];
bool visited[100001];
int level[100001];
int parent[100001][LOG];
int V, Q;

void dfs(int cur_node, int cur_level) {
    visited[cur_node] = true;

    for (size_t i = 0; i < tree[cur_node].size(); i++) {
        int next_node = tree[cur_node][i];
        if (visited[next_node]) continue;

        parent[next_node][0] = cur_node;
        level[next_node] = cur_level + 1;
        dfs(next_node, cur_level + 1);
    }
}

void make_sparse_table() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= V; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int get_lca(int x, int y) {
    if (level[x] < level[y]) {
        swap(x, y);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (((level[x] - level[y]) & (1 << i)) > 0) {
            x = parent[x][i];
        }
    }

    if (x == y) {
        return x;
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V;

    for (int i = 1; i < V; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, 0);
    parent[1][0] = 1;
    make_sparse_table();

    cin >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;

        cout << get_lca(x, y) << '\n';
    }
}