#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[100001];
int parent[100001];
bool visited[100001];
int dp[100001];
int V;

void make_parent() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }
}

bool can_first_win(int cur) {
    if (dp[cur] != 0) {
        return dp[cur] == 1;
    }

    if (graph[cur].size() == 1 && cur != 1) {
        dp[cur] = 2;
        return false;
    }

    for (int nxt : graph[cur]) {
        if (nxt == parent[cur]) {
            continue;
        }

        if (!can_first_win(nxt)) {
            dp[cur] = 1;
            return true;
        }
    }

    dp[cur] = 2;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V;

    for (int i = 1; i <= V - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    make_parent();

    for (int i = 1; i <= V; i++) {
        if (can_first_win(i)) {
            cout << "donggggas\n";
        } else {
            cout << "uppercut\n";
        }
    }
}
