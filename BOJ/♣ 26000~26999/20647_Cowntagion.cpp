#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];

void bfs() {
    int total_time = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int required_covids = 0;

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int next_node = graph[cur][i];

            if (!visited[next_node]) {
                required_covids += 1;
                total_time += 1;
                q.push(next_node);
                visited[next_node] = true;
            }
        }

        int cur_covids = 1;

        while (cur_covids <= required_covids) {
            cur_covids *= 2;
            total_time += 1;
        }
    }

    cout << total_time;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();
}