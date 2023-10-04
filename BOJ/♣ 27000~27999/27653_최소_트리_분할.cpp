#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct Node {
    int n, d;
};

bool operator<(const Node& a, const Node& b) {
    return a.d > b.d;
}

vector<int> graph[100001];
Node nodes[100001];
bool activated[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int degree;
        cin >> degree;

        nodes[i] = {i, degree};
    }

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    sort(nodes + 1, nodes + N + 1);

    ll cur_time = nodes[1].d;
    ll graph_count = 0;
    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        if (nodes[i].d != cur_time) {
            answer += graph_count * (cur_time - nodes[i].d);
            cur_time = nodes[i].d;
        }

        activated[nodes[i].n] = true;
        graph_count += 1;

        for (size_t j = 0; j < graph[nodes[i].n].size(); j++) {
            int adjacent = graph[nodes[i].n][j];

            if (activated[adjacent]) {
                graph_count -= 1;
            }
        }
    }

    answer += graph_count * cur_time;

    cout << answer;
}