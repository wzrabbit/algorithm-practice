#include <algorithm>
#include <iostream>
#include <vector>
#define LOG 17
typedef long long ll;
using namespace std;

struct TreeNode {
    int p, d;
};

vector<TreeNode> tree[100001];
int level[100001];
bool visited[100001];
int parent[100001][LOG];
ll dist[100001][LOG];
int N, Q;

void dfs(int cur_node, int cur_level) {
    visited[cur_node] = true;

    for (size_t i = 0; i < tree[cur_node].size(); i++) {
        int next_node = tree[cur_node][i].p;
        int next_dist = tree[cur_node][i].d;
        if (visited[next_node]) continue;

        parent[next_node][0] = cur_node;
        dist[next_node][0] = next_dist;
        level[next_node] = cur_level + 1;
        dfs(next_node, cur_level + 1);
    }
}

void make_sparse_tables() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
        }
    }
}

ll get_dist(int x, int y) {
    ll total_dist = 0;

    if (level[x] < level[y]) {
        swap(x, y);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (((level[x] - level[y]) & (1 << i)) > 0) {
            total_dist += dist[x][i];
            x = parent[x][i];
        }
    }

    if (x == y) {
        return total_dist;
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            total_dist += dist[x][i] + dist[y][i];
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    total_dist += dist[x][0] + dist[y][0];
    return total_dist;
}

int get_lca_level(int x, int y) {
    if (level[x] < level[y]) {
        swap(x, y);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (((level[x] - level[y]) & (1 << i)) > 0) {
            x = parent[x][i];
        }
    }

    if (x == y) {
        return level[x];
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return level[parent[x][0]];
}

int get_kth_node(int x, int y, int k) {
    int parent_level = get_lca_level(x, y);
    int x_dist = level[x] - parent_level;
    int y_dist = level[y] - parent_level;

    int core, gap;

    if (k <= x_dist + 1) {
        core = x;
        gap = k - 1;
    } else {
        core = y;
        gap = x_dist + y_dist + 1 - k;
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if ((gap & (1 << i)) > 0) {
            core = parent[core][i];
        }
    }

    return core;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
    }

    dfs(1, 0);
    make_sparse_tables();

    cin >> Q;

    while (Q--) {
        int query, u, v, k;
        cin >> query;

        if (query == 1) {
            cin >> u >> v;
            cout << get_dist(u, v) << '\n';
        } else {
            cin >> u >> v >> k;
            cout << get_kth_node(u, v, k) << '\n';
        }
    }
}