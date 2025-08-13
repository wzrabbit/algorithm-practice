#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, R;
bool visited[200001];
int answer[200001];
vector<int> graph[200001];

void perform_bfs() {
    queue<int> q;
    q.push(R);
    int id = 1;
    visited[R] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        answer[cur] = id;
        id += 1;

        for (int nxt : graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;

                q.push(nxt);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> R;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    perform_bfs();

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }
}
