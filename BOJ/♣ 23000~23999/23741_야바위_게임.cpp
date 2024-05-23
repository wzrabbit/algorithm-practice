#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct QData {
    int n, d;
};

vector<int> graph[1001];
int dist[2][1001];
int V, E, X, Y;

void perform_bfs() {
    fill(&dist[0][1], &dist[1][V + 1], -1);
    queue<QData> q;
    q.push({X, 0});

    while (!q.empty()) {
        QData cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i];
            bool next_layer = 1 - cur.d % 2;

            if (dist[next_layer][next_node] == -1) {
                dist[next_layer][next_node] = cur.d + 1;
                q.push({next_node, cur.d + 1});
            }
        }
    }
}

void print_answer() {
    vector<int> answer;

    for (int i = 1; i <= V; i++) {
        if (dist[0][i] != -1 && dist[0][i] >= 1 && dist[0][i] <= Y && dist[0][i] % 2 == Y % 2) {
            answer.push_back(i);
            continue;
        }

        if (dist[1][i] != -1 && dist[1][i] >= 1 && dist[1][i] <= Y && dist[1][i] % 2 == Y % 2) {
            answer.push_back(i);
        }
    }

    if (answer.empty()) {
        cout << -1;
    } else {
        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i] << ' ';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> X >> Y;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    perform_bfs();
    print_answer();
}
