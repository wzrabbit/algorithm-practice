#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parent[300001];
bool visited[300001];
bool is_root[300001];
vector<vector<int>> graph;
vector<pair<int, int>> ans;

void traverse(int cur) {
    visited[cur] = true;
    for (size_t i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (!visited[nxt]) {
            traverse(nxt);
            ans.push_back(make_pair(nxt, cur));
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q, M;
    cin >> N >> Q;
    graph.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
        if (i == parent[i])
            is_root[i] = true;
        else {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
    }

    cin >> M;
    cout << N << ' ' << Q << '\n';

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        cout << 2 << ' ' << x << '\n';
    }

    for (int i = 1; i <= N; i++) {
        if (is_root[i])
            traverse(i);
    }

    for (int i = 0; i < Q - M - ans.size(); i++)
        cout << "1 1 1" << '\n';

    for (size_t i = 0; i < ans.size(); i++)
        cout << "1 " << ans[i].first << ' ' << ans[i].second << '\n';
}