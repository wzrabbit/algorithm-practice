#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000
using namespace std;

struct Node {
    int n, d;
};

vector<int> graph[100001];
int dist[100001];
bool visited[100001];
int previous[100001];
int adj_count[100001];

void traverse(int start, int end) {
    queue<Node> q;
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.n == end) {
            return;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            adj_count[cur.n] += 1;

            int next_node = graph[cur.n][i];

            if (!visited[next_node]) {
                visited[next_node] = true;
                dist[next_node] = cur.d + 1;
                previous[next_node] = cur.n;
                q.push({next_node, cur.d + 1});
            }
        }
    }
}

bool can_first_win(int end) {
    int cur_node = end;

    while (true) {
        if (adj_count[cur_node] >= 3 && dist[cur_node] % 2 == 1 && cur_node != end) {
            return false;
        }

        if (previous[cur_node] == 0) {
            break;
        }

        cur_node = previous[cur_node];
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S, E;
    cin >> N >> S >> E;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    traverse(S, E);

    if (can_first_win(E)) {
        cout << "First";
        return 0;
    }

    cout << "Second";
}
