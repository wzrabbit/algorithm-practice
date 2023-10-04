#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int n, d;
};

vector<int> graph[300001];
bool visited[300001];
int di[2] = {-1, 1};

int bfs(int S, int E, int N) {
    queue<Node> q;
    visited[S] = true;
    q.push({S, 0});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.n == E) {
            return cur.d;
        }

        for (int i = 0; i <= 1; i++) {
            int next_node = cur.n + di[i];

            if (next_node < 1 || next_node > N || visited[next_node]) {
                continue;
            }

            visited[next_node] = true;
            q.push({next_node, cur.d + 1});
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i];

            if (next_node < 1 || next_node > N || visited[next_node]) {
                continue;
            }

            visited[next_node] = true;
            q.push({next_node, cur.d + 1});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, S, E;
    cin >> N >> M >> S >> E;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << bfs(S, E, N);
}