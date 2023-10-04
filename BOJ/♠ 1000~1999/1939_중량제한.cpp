#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int n, l;
};

vector<Node> graph[10001];
bool visited[10001];
int N, M, start_node, end_node;

bool is_possible(int weight) {
    fill(visited + 1, visited + N + 1, false);

    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end_node) {
            return true;
        }

        for (size_t i = 0; i < graph[cur].size(); i++) {
            Node next_node = graph[cur][i];

            if (!visited[next_node.n] && weight <= next_node.l) {
                q.push(next_node.n);
                visited[next_node.n] = true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        graph[s].push_back({e, l});
        graph[e].push_back({s, l});
    }

    cin >> start_node >> end_node;

    int start = 1;
    int end = 1'000'000'000;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}