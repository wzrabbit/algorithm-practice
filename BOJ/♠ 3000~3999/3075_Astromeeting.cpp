#include <algorithm>
#include <iostream>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

ll dist[101][101];
int participants[101];
int N, V, E;

void perform_floyd() {
    for (int m = 1; m <= V; m++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
            }
        }
    }
}

ll get_total_dist(int no) {
    ll total_dist = 0;

    for (int i = 1; i <= N; i++) {
        int cur = participants[i];

        if (dist[cur][no] >= INF) {
            return INF;
        }

        total_dist += dist[cur][no] * dist[cur][no];
    }

    return total_dist;
}

void solve() {
    cin >> N >> V >> E;

    fill(&dist[1][1], &dist[V][V + 1], INF);

    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        cin >> participants[i];
    }

    for (int i = 1; i <= E; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        dist[u][v] = min(dist[u][v], d);
        dist[v][u] = min(dist[v][u], d);
    }

    perform_floyd();

    ll best_total_dist = INF;
    int best_no = 0;

    for (int i = 1; i <= V; i++) {
        ll cur_total_dist = get_total_dist(i);

        if (cur_total_dist < best_total_dist) {
            best_no = i;
            best_total_dist = cur_total_dist;
        }
    }

    cout << best_no << ' ' << best_total_dist << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
