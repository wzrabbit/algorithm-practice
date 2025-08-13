#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info {
    int n, c;
};

int infos[101][101];
int indegree[101];
vector<Info> graph[101];
int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        graph[v].push_back({u, c});
        indegree[u] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            infos[i][i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (Info next : graph[cur]) {
            indegree[next.n] -= 1;

            for (int i = 1; i <= N; i++) {
                infos[next.n][i] += infos[cur][i] * next.c;
            }

            if (indegree[next.n] == 0) {
                q.push(next.n);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (infos[N][i] > 0) {
            cout << i << ' ' << infos[N][i] << '\n';
        }
    }
}
