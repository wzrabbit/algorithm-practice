#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int n, l;
};

vector<int> graph[100000];
int edge[100000];
bool is_deleted[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[u] += 1;
        edge[v] += 1;
    }

    int one_edge = 0;
    int level = -1;
    queue<Node> q;

    for (int i = 0; i < N; i++) {
        if (edge[i] == 1) {
            q.push({i, 0});
            one_edge += 1;
        }
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.l > level) {
            if (one_edge <= 2) {
                break;
            }

            level = cur.l;
        }

        is_deleted[cur.n] = true;

        if (edge[cur.n] == 1) {
            one_edge -= 1;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i];

            if (is_deleted[next_node]) {
                continue;
            }

            edge[next_node] -= 1;

            if (edge[next_node] == 1) {
                one_edge += 1;
                q.push({next_node, cur.l + 1});
            }

            if (edge[next_node] == 0) {
                one_edge -= 1;
            }
        }
    }

    vector<int> lines;

    for (int i = 0; i < N; i++) {
        if (!is_deleted[i]) {
            lines.push_back(i);
        }
    }

    sort(lines.begin(), lines.end());

    for (size_t i = 0; i < lines.size(); i++) {
        cout << lines[i] << ' ';
    }
}