#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char grid[49][49];
int capacity[4444][4444];
int flow[4444][4444];
vector<int> graph[4444];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void make_graph() {
    for (int r = 1; r <= R; r++) {
        for (int c = 2 - r % 2; c <= C; c += 2) {
            if (grid[r][c] == 'X') {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > R || nc < 1 || nc > C ||
                    grid[nr][nc] == 'X') {
                    continue;
                }

                int source = 0;
                int black = ((r - 1) * C + c) * 2 - 1;
                int white = ((nr - 1) * C + nc) * 2 - 1;
                int black2 = black + 1;
                int white2 = white + 1;
                int sink = 2 * R * C + 1;

                if (nr % 2 == 1) {
                    graph[source].push_back(white);
                    graph[white].push_back(white2);
                    graph[white2].push_back(black);
                    graph[white].push_back(source);
                    graph[white2].push_back(white);
                    graph[black].push_back(white2);
                    capacity[source][white] = 1;
                    capacity[white][white2] = 1;
                    capacity[white2][black] = 1;
                    continue;
                }

                graph[black].push_back(black2);
                graph[black2].push_back(white);
                graph[white].push_back(white2);
                graph[white2].push_back(sink);
                graph[black2].push_back(black);
                graph[white].push_back(black2);
                graph[white2].push_back(white);
                graph[sink].push_back(white2);
                capacity[black][black2] = 1;
                capacity[black2][white] = 1;
                capacity[white][white2] = 1;
                capacity[white2][sink] = 1;
            }
        }
    }
}

int get_max_flow() {
    int prev[4444];
    int total_flow = 0;
    int source = 0;
    int sink = 2 * R * C + 1;

    while (true) {
        fill(prev, prev + sink + 1, -1);
        queue<int> q;
        q.push(source);

        while (!q.empty() && prev[sink] == -1) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (flow[cur][nxt] < capacity[cur][nxt] && prev[nxt] == -1) {
                    q.push(nxt);
                    prev[nxt] = cur;
                }
            }
        }

        if (prev[sink] == -1) {
            break;
        }

        for (int i = sink; i != source; i = prev[i]) {
            flow[prev[i]][i] += 1;
            flow[i][prev[i]] -= 1;
        }

        total_flow += 1;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    make_graph();
    cout << get_max_flow();
}
