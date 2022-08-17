#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int parent[100001];
int scale[100001];
char color[100002];
vector<vector<int>> graph;
vector<pair<int, int>> connect;

int get_parent(int child) {
    if (parent[child] == -1) return child;
    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a != b) {
        parent[a] = b;
        scale[b] += scale[a];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    fill(&parent[1], &parent[N + 1], -1);
    fill(&scale[1], &scale[N + 1], 0);
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        connect.push_back(make_pair(s, e));
    }

    for (int i = 1; i <= N; i++) {
        cin >> color[i];
        if (color[i] == 'R')
            scale[i] = 1;
    }

    for (size_t i = 0; i < connect.size(); i++) {
        int s = connect[i].first;
        int e = connect[i].second;

        if (color[s] == color[e] && color[s] == 'R')
            merge(s, e);

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    ll total = 0;
    for (int i = 1; i <= N; i++) {
        if (color[i] == 'R')
            continue;

        for (size_t j = 0; j < graph[i].size(); j++)
            total += (ll)scale[get_parent(graph[i][j])];
    }

    cout << total;
}