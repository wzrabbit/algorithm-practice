#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Query {
    int a, b;
};

vector<Query> query[2];
vector<int> graph[2][1001];
bool visited[1001];
int N;

void write_queries(int no) {
    queue<int> q;
    q.push(1);
    fill(visited + 1, visited + N + 1, false);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[no][cur].size(); i++) {
            int next_node = graph[no][cur][i];

            if (!visited[next_node]) {
                if (cur != 1) {
                    query[no].push_back({cur, next_node});
                }

                visited[next_node] = true;
                q.push(next_node);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N - 1; j++) {
            int u, v;
            cin >> u >> v;
            graph[i][u].push_back(v);
            graph[i][v].push_back(u);
        }
    }

    for (int i = 0; i < 2; i++) {
        write_queries(i);
    }

    cout << query[0].size() + query[1].size() << '\n';

    for (size_t i = 0; i < query[0].size(); i++) {
        cout << query[0][i].b << ' ' << query[0][i].a << ' ' << 1 << '\n';
    }

    for (int i = (int)query[1].size() - 1; i >= 0; i--) {
        cout << query[1][i].b << ' ' << 1 << ' ' << query[1][i].a << '\n';
    }
}