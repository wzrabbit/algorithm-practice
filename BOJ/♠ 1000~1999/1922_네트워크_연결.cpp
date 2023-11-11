#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Edge {
    int u, v, d;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.d < b.d;
}

int parent[1001];
Edge edges[100001];

int get_parent(int child) {
    if (parent[child] == 0) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

bool merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) {
        return false;
    }

    parent[a] = b;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].d;
    }

    sort(edges + 1, edges + E + 1);

    int success_count = 0;
    int index = 0;
    ll cost = 0;

    while (success_count < V - 1) {
        Edge cur = edges[index];

        if (merge(cur.u, cur.v)) {
            success_count += 1;
            cost += cur.d;
        }

        index += 1;
    }

    cout << cost;
}