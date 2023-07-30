#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Loc {
    int n, d;
};

vector<int> graph[100001];
bool visited[100001];
int V, E;

int bfs() {
    queue<Loc> q;
    q.push({1, 0});
    visited[1] = true;
    int max_distance = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (cur.n == V) {
            return cur.d - 1;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i];

            if (!visited[next_node]) {
                visited[next_node] = true;
                q.push({next_node, cur.d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << bfs();
}