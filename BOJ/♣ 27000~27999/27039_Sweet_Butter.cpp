#include <iostream>
#define INF 90000001
using namespace std;

int cow[801];
int dist[801][801];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int M, V, E;
    cin >> M >> V >> E;

    for (int i = 1; i <= M; i++) {
        int cur;
        cin >> cur;

        cow[cur] += 1;
    }

    fill(&dist[1][1], &dist[V][V + 1], INF);

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        dist[u][v] = d;
        dist[v][u] = d;
    }

    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }

    for (int m = 1; m <= V; m++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                if (dist[s][m] + dist[m][e] < dist[s][e]) {
                    dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }
    }

    int best = INF;

    for (int s = 1; s <= V; s++) {
        int cur = 0;

        for (int e = 1; e <= V; e++) {
            cur += dist[s][e] * cow[e];
        }

        best = min(best, cur);
    }

    cout << best;
}