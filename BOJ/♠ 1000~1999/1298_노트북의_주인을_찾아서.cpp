#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'000
using namespace std;

int flow[202][202];
int capacity[202][202];
int history[202];
vector<int> graph[202];
int N, M;

void make_graph() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        capacity[u][N + v] = 1;
        graph[u].push_back(N + v);
        graph[N + v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        capacity[0][i] = 1;
        graph[0].push_back(i);
        graph[i].push_back(0);

        capacity[N + i][N * 2 + 1] = 1;
        graph[N + i].push_back(N * 2 + 1);
        graph[N * 2 + 1].push_back(N + i);
    }
}

int get_max_flow() {
    int total_flow = 0;

    while (true) {
        fill(history, history + N * 2 + 2, -1);
        queue<int> q;
        q.push(0);

        while (!q.empty() && history[N * 2 + 1] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && history[nxt] == -1) {
                    q.push(nxt);
                    history[nxt] = cur;
                }
            }
        }

        if (history[N * 2 + 1] == -1) {
            break;
        }

        for (int i = N * 2 + 1; i != 0; i = history[i]) {
            flow[history[i]][i] += 1;
            flow[i][history[i]] -= 1;
        }

        total_flow += 1;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    make_graph();
    cout << get_max_flow();
}
