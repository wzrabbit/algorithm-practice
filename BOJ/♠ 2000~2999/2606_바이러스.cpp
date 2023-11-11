// BFS 구현 예시 - C++17

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];
int infected_count = 0;

// 이게 bfs 코드입니다. 이 부분만 집중해서 보셔도 됩니다
void bfs(int start_node) {
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        infected_count += 1;  // 정점이 방문될 때마다 감염 횟수 + 1

        for (size_t i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];

            if (!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);

    cout << infected_count - 1;  // 1번 컴퓨터는 제외
}