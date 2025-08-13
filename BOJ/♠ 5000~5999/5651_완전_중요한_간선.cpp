#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 20001
using namespace std;

int flow[302][302];
int capacity[302][302];
int prv[302];
bool visited[302];
vector<int> graph[302];
vector<pair<int, int>> edges;
int V, E;

void init() {
    fill(&flow[1][1], &flow[V][V + 1], 0);
    fill(&capacity[1][1], &capacity[V][V + 1], 0);
    edges.clear();

    for (int i = 1; i <= V; i++) {
        graph[i].clear();
    }
}

void perform_flow() {
    while (true) {
        fill(prv + 1, prv + V + 1, -1);
        queue<int> q;
        q.push(1);

        while (!q.empty() && prv[V] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    prv[nxt] = cur;
                    q.push(nxt);
                }
            }
        }

        if (prv[V] == -1) {
            return;
        }

        int path_flow = INF;

        for (int i = V; i != 1; i = prv[i]) {
            path_flow = min(path_flow, capacity[prv[i]][i] - flow[prv[i]][i]);
        }

        for (int i = V; i != 1; i = prv[i]) {
            flow[prv[i]][i] += path_flow;
            flow[i][prv[i]] -= path_flow;
        }
    }
}

bool is_crucial_edge(int start, int end) {
    if (flow[start][end] < capacity[start][end]) {
        return false;
    }

    fill(visited + 1, visited + V + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if ((cur != start || nxt != end) && !visited[nxt] && flow[cur][nxt] < capacity[cur][nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return !visited[end];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    
    while (T--) {
        cin >> V >> E;
        init();

        for (int i = 1; i <= E; i++) {
            int u, v, d;
            cin >> u >> v >> d;

            capacity[u][v] += d;
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges.push_back(make_pair(u, v));
        }

        perform_flow();

        int crucial_edge_count = 0;

        for (pair<int, int> edge : edges) {
            int u = edge.first;
            int v = edge.second;

            if (is_crucial_edge(u, v)) {
                crucial_edge_count += 1;
            }
        }

        cout << crucial_edge_count << '\n';
    }
}
