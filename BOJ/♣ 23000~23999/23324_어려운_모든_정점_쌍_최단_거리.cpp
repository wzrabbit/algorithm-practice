#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int bfs() {
    queue<int> q;
    int cnt = 0;
    visited[1] = true;
    q.push(1);

    while (q.size()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E, K;
    cin >> V >> E >> K;

    graph.resize(V + 1);
    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);

    for (int i = 1; i <= E; i++) {
        int s, e;
        cin >> s >> e;

        if (i != K) {
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
    }

    int res = bfs();
    cout << (long long)res * (long long)(V - res);
}