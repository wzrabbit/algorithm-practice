#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

struct Edge {
    int s, e;
};

struct Node {
    int n, d;
};

Edge edges[2001];
int parent[4001];
bool visited[4001];
vector<int> graph[4001];
vector<int> edge_values;
map<int, int> compressed;
int dist[4001][4001];

int V, E, N, Q;

void compress() {
    sort(edge_values.begin(), edge_values.end());

    for (size_t i = 0; i < edge_values.size(); i++) {
        if (i != 0 && edge_values[i - 1] == edge_values[i]) {
            continue;
        }

        N += 1;

        compressed[edge_values[i]] = N;
    }
}

int get_parent(int child) {
    if (parent[child] == child) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}
void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[a] = b;
    }
}

void traverse(int start) {
    queue<Node> q;
    q.push({start, 0});
    fill(visited + 1, visited + N + 1, false);
    visited[start] = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        dist[start][cur.n] = cur.d;

        for (size_t j = 0; j < graph[cur.n].size(); j++) {
            int nxt = graph[cur.n][j];

            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push({nxt, cur.d + 1});
            }
        }
    }
}

void make_dist() {
    fill(&dist[1][1], &dist[N][N + 1], -1);

    for (int i = 1; i <= N; i++) {
        traverse(i);
    }
}

bool is_one_group() {
    if (N < V) {
        return false;
    }

    int first_node_parent = get_parent(1);

    for (int i = 2; i <= N; i++) {
        if (get_parent(i) != first_node_parent) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> Q;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        edges[i] = {u, v};
        edge_values.push_back(u);
        edge_values.push_back(v);
    }

    compress();

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= E; i++) {
        int u = compressed[edges[i].s];
        int v = compressed[edges[i].e];
        graph[u].push_back(v);
        graph[v].push_back(u);
        merge(u, v);
    }

    make_dist();

    bool one_group = is_one_group();

    while (Q--) {
        int s, e;
        cin >> s >> e;

        if (s == e) {
            cout << 0 << '\n';
            continue;
        }

        if (compressed.find(s) == compressed.end() ||
            compressed.find(e) == compressed.end()) {
            cout << 1 << '\n';
            continue;
        }

        int u = compressed[s];
        int v = compressed[e];

        if (dist[u][v] == -1) {
            cout << 1 << '\n';
            continue;
        }

        if (is_one_group()) {
            cout << dist[u][v] << '\n';
            continue;
        }

        cout << min(dist[u][v], 2) << '\n';
    }
}
