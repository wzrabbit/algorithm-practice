#include <algorithm>
#include <iostream>
#include <vector>
#define LOG 17
#define INF 1000001
using namespace std;

struct TreeNode {
    int node, dist;
};

vector<TreeNode> tree[100001];
int level[100001];
int parent[100001][LOG];
int min_length[100001][LOG];
int max_length[100001][LOG];
bool visited[100001];
int N, Q;

void dfs(int cur_node, int cur_level) {
    visited[cur_node] = true;
    level[cur_node] = cur_level;

    for (size_t i = 0; i < tree[cur_node].size(); i++) {
        TreeNode nxt = tree[cur_node][i];
        if (visited[nxt.node]) {
            continue;
        }

        parent[nxt.node][0] = cur_node;
        min_length[nxt.node][0] = nxt.dist;
        max_length[nxt.node][0] = nxt.dist;
        dfs(nxt.node, cur_level + 1);
    }
}

void make_sparse_tables() {
    min_length[1][0] = INF;
    max_length[1][0] = 0;

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            min_length[i][j] = min(min_length[i][j - 1], min_length[parent[i][j - 1]][j - 1]);
            max_length[i][j] = max(max_length[i][j - 1], max_length[parent[i][j - 1]][j - 1]);
        }
    }
}

void print_min_max_path(int u, int v) {
    int min_answer = INF;
    int max_answer = 0;

    if (level[u] < level[v]) {
        swap(u, v);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (((level[u] - level[v]) & (1 << i)) > 0) {
            min_answer = min(min_answer, min_length[u][i]);
            max_answer = max(max_answer, max_length[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) {
        cout << min_answer << ' ' << max_answer << '\n';
        return;
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            min_answer = min(min_answer, min_length[u][i]);
            min_answer = min(min_answer, min_length[v][i]);
            max_answer = max(max_answer, max_length[u][i]);
            max_answer = max(max_answer, max_length[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    min_answer = min(min_answer, min_length[u][0]);
    min_answer = min(min_answer, min_length[v][0]);
    max_answer = max(max_answer, max_length[u][0]);
    max_answer = max(max_answer, max_length[v][0]);

    cout << min_answer << ' ' << max_answer << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        tree[u].push_back({v, d});
        tree[v].push_back({u, d});
    }

    dfs(1, 0);
    make_sparse_tables();

    cin >> Q;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        print_min_max_path(u, v);
    }
}