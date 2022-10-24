#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[101];
bool vis[101];
int vis_cnt[101];

void bfs(int start, int N) {
    queue<int> q;
    fill(vis + 1, vis + N + 1, false);
    vis[start] = true;
    q.push(start);

    while (q.size()) {
        int cur = q.front();
        vis_cnt[cur]++;
        q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
    }

    for (int i = 1; i <= N; i++) {
        bfs(i, N);
    }

    bool success = false;
    for (int i = 1; i <= N; i++) {
        if (vis_cnt[i] == N) {
            success = true;
            cout << i;
            break;
        }
    }

    if (!success) {
        cout << -1;
    }
}