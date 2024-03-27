#include <algorithm>
#include <iostream>
#define INF 1'000'001
typedef long long ll;
using namespace std;

int input[101][101];
int dist[101][101][101];
int V, E, Q;

void make_floyd(int ban) {
    for (int r = 1; r <= V; r++) {
        for (int c = 1; c <= V; c++) {
            dist[ban][r][c] = input[r][c];
        }
    }

    for (int m = 1; m <= V; m++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                if (m == s || s == e || e == m || s == ban || m == ban || e == ban) {
                    continue;
                }

                dist[ban][s][e] = min(dist[ban][s][e], dist[ban][s][m] + dist[ban][m][e]);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> Q;

    fill(&input[1][1], &input[V][V + 1], INF);

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        input[u][v] = d;
    }

    for (int i = 1; i <= V; i++) {
        make_floyd(i);
    }

    while (Q--) {
        int s, b, e;
        cin >> s >> b >> e;

        if (dist[b][s][e] == INF) {
            cout << "No\n";
        } else {
            cout << dist[b][s][e] << '\n';
        }
    }
}
