#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct edge {
    int s, e;
};

int parent[100001];
int scale[100001];
int query[100001];
edge graph[100001];
bool is_blocked[100001];

int get_parent(int child) {
    if (parent[child] == 0) return child;
    return get_parent(parent[child]);
}

ll merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        ll calc = scale[a] * scale[b];

        if (scale[a] >= scale[b]) {
            parent[b] = a;
            scale[a] += scale[b];
        } else {
            parent[a] = b;
            scale[b] += scale[a];
        }

        return calc;
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E, Q;
    ll cost = 0;
    cin >> V >> E >> Q;
    fill(scale + 1, scale + V + 1, 1);

    for (int i = 1; i <= E; i++) {
        int s, e;
        cin >> s >> e;
        graph[i] = {s, e};
    }

    for (int i = 1; i <= Q; i++) {
        cin >> query[i];
        is_blocked[query[i]] = true;
    }

    for (int i = 1; i <= E; i++) {
        if (!is_blocked[i]) {
            merge(graph[i].s, graph[i].e);
        }
    }

    for (int i = Q; i >= 1; i--)
        cost += merge(graph[query[i]].s, graph[query[i]].e);

    cout << cost;
}