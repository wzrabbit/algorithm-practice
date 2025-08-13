#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 101
using namespace std;

int flow[501][501];
int capacity[501][501];
int prv[501];
vector<int> graph[501];
int V, E, S, T;

int get_max_flow() {
    int total_flow = 0;

    while (true) {
        fill(prv + 1, prv + V + 1, -1);
        queue<int> q;
        q.push(S);

        while (!q.empty() && prv[T] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    q.push(nxt);
                    prv[nxt] = cur;
                }
            }
        }

        if (prv[T] == -1) {
            break;
        }

        int path_flow = INF;

        for (int i = T; i != S; i = prv[i]) {
            path_flow = min(path_flow, capacity[prv[i]][i] - flow[prv[i]][i]);
        }

        for (int i = T; i != S; i = prv[i]) {
            flow[prv[i]][i] += path_flow;
            flow[i][prv[i]] -= path_flow;
        }

        total_flow += path_flow;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] = d;
        capacity[v][u] = d;
    }

    cin >> S >> T;

    cout << get_max_flow();
}
