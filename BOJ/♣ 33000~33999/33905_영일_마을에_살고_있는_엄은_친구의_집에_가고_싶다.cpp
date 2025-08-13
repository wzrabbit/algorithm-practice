#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, K;
bool is_closed[5010];
bool visited[5010];
vector<int> graph[5010];

int get_visited_count() {
    int answer = 0;
    fill(visited + 1, visited + V + 1, false);
    visited[1] = true;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (!visited[nxt] && !is_closed[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                answer += 1;
            }
        }
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> K;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= K; i++) {
        int cur;
        cin >> cur;

        is_closed[cur] = true;
    }

    cout << get_visited_count();
}
