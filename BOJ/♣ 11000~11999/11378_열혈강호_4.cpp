#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'000
using namespace std;

int flow[2005][2005];
int capacity[2005][2005];
int prv[2005];
vector<int> graph[2005];
int N, M, K;

void construct_graph() {
    cin >> N >> M >> K;

    capacity[0][N + M + 1] = M;
    graph[0].push_back(N + M + 1);
    graph[N + M + 1].push_back(0);

    capacity[0][N + M + 2] = K;
    graph[0].push_back(N + M + 2);
    graph[N + M + 2].push_back(0);

    for (int i = 1; i <= N; i++) {
        capacity[N + M + 1][i] = 1;
        graph[N + M + 1].push_back(i);
        graph[i].push_back(N + M + 1);
    }

    for (int i = 1; i <= N; i++) {
        capacity[N + M + 2][i] = K;
        graph[N + M + 2].push_back(i);
        graph[i].push_back(N + M + 2);
    }

    for (int i = 1; i <= N; i++) {
        int repeat;
        cin >> repeat;

        for (int j = 1; j <= repeat; j++) {
            int cur;
            cin >> cur;

            capacity[i][N + cur] = 1;
            graph[i].push_back(N + cur);
            graph[N + cur].push_back(i);
        }
    }

    for (int i = N + 1; i <= N + M; i++) {
        capacity[i][N + M + 3] = 1;
        graph[i].push_back(N + M + 3);
        graph[N + M + 3].push_back(i);
    }
}

int get_max_flow() {
    int total_flow = 0;

    while (true) {
        fill(prv, prv + 2005, -1);
        queue<int> q;
        q.push(0);

        while (!q.empty() && prv[N + M + 3] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    q.push(nxt);
                    prv[nxt] = cur;
                }
            }
        }

        if (prv[N + M + 3] == -1) {
            break;
        }

        for (int i = N + M + 3; i != 0; i = prv[i]) {
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
