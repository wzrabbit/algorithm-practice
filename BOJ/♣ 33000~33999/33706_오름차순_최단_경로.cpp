#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[200001];
bool visited[200001];
vector<int> graph[200001];

bool is_traverse_possible() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    int current_id = 1;
    visited[1] = true;

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (cur != current_id) {
            return false;
        }

        current_id += 1;

        for (int nxt : graph[cur]) {
            if (!visited[nxt]) {
                pq.push(nxt);
                visited[nxt] = true;
            }
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << (is_traverse_possible() ? "YES" : "NO");
}
