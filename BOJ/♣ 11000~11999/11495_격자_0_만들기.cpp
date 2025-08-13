#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 2'500'001
using namespace std;

int grid[51][51];
int capacity[2502][2502];
int flow[2502][2502];
int prv[2502];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<int> graph[2502];
int R, C;

void init() {
    fill(&capacity[0][0], &capacity[R * C + 1][R * C + 2], 0);
    fill(&flow[0][0], &flow[R * C + 1][R * C + 2], 0);

    for (int i = 0; i <= R * C + 1; i++) {
        graph[i].clear();
    }
}

void make_graph() {
    for (int r = 1; r <= R; r++) {
        for (int c = 2 - r % 2; c <= C; c += 2) {
            int u = (r - 1) * C + c;

            capacity[0][u] = grid[r][c];
            graph[0].push_back(u);
            graph[u].push_back(0);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > R || nc < 1 || nc > C) {
                    continue;
                }

                int v = (nr - 1) * C + nc;

                capacity[u][v] = INF;
                graph[u].push_back(v);
                graph[v].push_back(u);

                capacity[v][R * C + 1] = grid[nr][nc];
                graph[v].push_back(R * C + 1);
                graph[R * C + 1].push_back(v);
            }
        }
    }
}

int get_max_flow() {
    int max_flow = 0;

    while (true) {
        fill(prv, prv + R * C + 2, -1);
        queue<int> q;
        q.push(0);

        while (!q.empty() && prv[R * C + 1] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prv[nxt] == -1) {
                    q.push(nxt);
                    prv[nxt] = cur;
                }
            }
        }

        if (prv[R * C + 1] == -1) {
            break;
        }

        int path_flow = INF;

        for (int i = R * C + 1; i != 0; i = prv[i]) {
            path_flow = min(path_flow, capacity[prv[i]][i] - flow[prv[i]][i]);
        }

        for (int i = R * C + 1; i != 0; i = prv[i]) {
            flow[prv[i]][i] += path_flow;
            flow[i][prv[i]] -= path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> R >> C;

        int sum = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                cin >> grid[r][c];
                sum += grid[r][c];
            }
        }

        init();
        make_graph();

        int max_flow = get_max_flow();
        cout << max_flow + sum - max_flow * 2 << '\n';
    }
}
