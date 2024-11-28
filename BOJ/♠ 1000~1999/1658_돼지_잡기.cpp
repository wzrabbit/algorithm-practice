#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'000
using namespace std;

struct Edge {
    int n, f, c, i;
};

vector<Edge> graph[100200];
int prv[100200];
int P, C;

void construct_graph() {
    cin >> P >> C;

    for (int i = 1; i <= P; i++) {
        int pig_count;
        cin >> pig_count;

        graph[0].push_back({i, 0, pig_count, int(graph[i].size())});
        graph[i].push_back({0, 0, 0, int(graph[0].size()) - 1});
    }

    for (int i = 1; i <= C - 1; i++) {
        for (int j = 1; j <= P; j++) {
            int u = (i - 1) * P + j;
            int v = u + P;

            graph[u].push_back({v, 0, INF, int(graph[v].size())});
            graph[v].push_back({u, 0, 0, int(graph[u].size()) - 1});
        }
    }

    for (int i = 1; i <= C; i++) {
        int key_count;
        cin >> key_count;

        for (int j = 1; j <= key_count; j++) {
            int cur;
            cin >> cur;

            int u = (i - 1) * P + cur;
            int v = P * C + i;

            graph[u].push_back({v, 0, INF, int(graph[v].size())});
            graph[v].push_back({u, 0, 0, int(graph[u].size()) - 1});

            v = P * C + C + i;

            if (i != C) {
                graph[u].push_back({v, 0, INF, int(graph[v].size())});
                graph[v].push_back({u, 0, 0, int(graph[u].size()) - 1});
            }

            u = v;
            v = i * P + cur;

            if (i != C) {
                graph[u].push_back({v, 0, INF, int(graph[v].size())});
                graph[v].push_back({u, 0, 0, int(graph[u].size()) - 1});
            }
        }

        int max_buy_count;
        cin >> max_buy_count;

        int u = P * C + i;
        int v = (P + 2) * C;

        graph[u].push_back({v, 0, max_buy_count, int(graph[v].size())});
        graph[v].push_back({u, 0, 0, int(graph[u].size()) - 1});
    }
}

int get_max_flow() {
    int total_flow = 0;
    int source = 0;
    int sink = (P + 2) * C;

    while (true) {
        fill(prv, prv + sink + 1, -1);
        queue<int> q;
        q.push(source);

        while (!q.empty() && prv[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (Edge nxt : graph[cur]) {
                if (nxt.f < nxt.c && prv[nxt.n] == -1) {
                    q.push(nxt.n);
                    prv[nxt.n] = cur;
                }
            }
        }

        if (prv[sink] == -1) {
            break;
        }

        int path_flow = INF;

        for (int i = sink; i != source; i = prv[i]) {
            int u = prv[i];
            for (Edge& j : graph[u]) {
                if (j.n == i) {
                    path_flow = min(path_flow, j.c - j.f);
                }
            }
        }

        for (int i = sink; i != source; i = prv[i]) {
            int u = prv[i];

            for (Edge& j : graph[u]) {
                if (j.n == i) {
                    j.f += path_flow;
                    graph[j.n][j.i].f -= path_flow;
                    break;
                }
            }
        }

        total_flow += path_flow;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    construct_graph();
    cout << get_max_flow();
}
