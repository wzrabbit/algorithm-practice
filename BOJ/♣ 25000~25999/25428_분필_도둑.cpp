#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct pr {
    ll node, amount;
};

ll parent[100001];
ll scale[100001];
bool activated[100001];
vector<vector<ll>> graph;
vector<pr> order;
ll max_scale = 1;
ll maximum = 0;

bool compare(pr a, pr b) {
    return a.amount > b.amount;
}

ll get_parent(ll child) {
    if (parent[child] == -1)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(ll a, ll b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        if (scale[a] > scale[b]) {
            parent[b] = a;
            scale[a] += scale[b];
            max_scale = max(scale[a], max_scale);
        } else {
            parent[a] = b;
            scale[b] += scale[a];
            max_scale = max(scale[b], max_scale);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;
    fill(&parent[0], &parent[N + 1], -1);
    fill(&scale[0], &scale[N + 1], 1);
    graph.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        order.push_back({i, a});
    }
    sort(order.begin(), order.end(), compare);

    for (int i = 0; i < N - 1; i++) {
        ll s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 0; i < N; i++) {
        pr cur = order[i];

        activated[cur.node] = true;
        for (size_t j = 0; j < graph[cur.node].size(); j++) {
            ll nxt = graph[cur.node][j];

            if (activated[nxt])
                merge(cur.node, nxt);
        }
        maximum = max(maximum, cur.amount * max_scale);
    }

    cout << maximum;
}