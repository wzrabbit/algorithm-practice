#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 400
using namespace std;

int flow[801][801];
int capacity[801][801];
int prv[801];
vector<int> graph[801];
int V, E;

void construct_graph() {
    cin >> V >> E;

    for (int i = 2; i <= V; i++) {
        int u = i * 2 - 1;
        int v = i * 2;

        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] = 1;
    }

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u * 2].push_back(v * 2 - 1);
        graph[v * 2].push_back(u * 2 - 1);
        graph[v * 2 - 1].push_back(u * 2);
        graph[u * 2 - 1].push_back(v * 2);
        capacity[u * 2][v * 2 - 1] = INF;
        capacity[v * 2][u * 2 - 1] = INF;
    }
}

int get_max_flow() {
    int total_flow = 0;

    while (true) {
        fill(prv + 1, prv + V * 2 + 1, -1);
        queue<int> q;
        q.push(2);

        while (!q.empty() && prv[3] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    q.push(nxt);
                    prv[nxt] = cur;
                }
            }
        }

        if (prv[3] == -1) {
            break;
        }

        for (int i = 3; i != 2; i = prv[i]) {
            flow[prv[i]][i] += 1;
            flow[i][prv[i]] -= 1;
        }

        total_flow += 1;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    construct_graph();
    cout << get_max_flow();
}
