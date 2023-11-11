#include <algorithm>
#include <iostream>
#include <queue>
#define INF 56'789'012
using namespace std;

int dist[1001];
int history[1001];
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> shortest_paths;
int V, E;

int dijkstra(int ban1, int ban2) {
    fill(dist + 1, dist + V + 1, INF);
    fill(history + 1, history + V + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int cur_d = pq.top().first;
        int cur_n = pq.top().second;
        pq.pop();

        if (cur_d > dist[cur_n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur_n].size(); i++) {
            int next_d = cur_d + graph[cur_n][i].first;
            int next_n = graph[cur_n][i].second;

            if (next_d < dist[next_n] && !((cur_n == ban1 && next_n == ban2) || (cur_n == ban2 && next_n == ban1))) {
                pq.push({next_d, next_n});
                history[next_n] = cur_n;
                dist[next_n] = next_d;
            }
        }
    }

    return dist[V];
}

void generate_history(int cur) {
    if (history[cur] == -1) {
        return;
    }

    generate_history(history[cur]);
    shortest_paths.push_back({history[cur], cur});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({d, v});
        graph[v].push_back({d, u});
    }

    int shortest_dist = dijkstra(-1, -1);
    int worst_dist = shortest_dist;

    if (shortest_dist == INF) {
        cout << -1;
        return 0;
    }

    generate_history(V);

    for (size_t i = 0; i < shortest_paths.size(); i++) {
        int ban1 = shortest_paths[i].first;
        int ban2 = shortest_paths[i].second;

        worst_dist = max(worst_dist, dijkstra(ban1, ban2));
    }

    if (worst_dist == INF) {
        cout << -1;
    } else {
        cout << worst_dist - shortest_dist;
    }
}