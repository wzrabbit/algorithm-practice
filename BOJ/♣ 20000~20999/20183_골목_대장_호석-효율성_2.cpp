#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct n_data {
    ll node, cost;
};

struct pq_data {
    ll node, money;
};

bool operator<(pq_data a, pq_data b) {
    return a.money < b.money;
}

vector<vector<n_data>> graph;
vector<ll> left_money;

bool dijkstra(ll start, ll end, ll limit, ll start_money) {
    fill(left_money.begin(), left_money.end(), -1);
    left_money[start] = start_money;
    priority_queue<pq_data> pq;
    pq.push({start, start_money});

    while (pq.size()) {
        pq_data cur = pq.top();
        pq.pop();

        if (cur.money < left_money[cur.node])
            continue;

        for (size_t i = 0; i < graph[cur.node].size(); i++) {
            n_data nxt = graph[cur.node][i];

            if (nxt.cost <= limit && cur.money - nxt.cost > left_money[nxt.node]) {
                pq.push({nxt.node, cur.money - nxt.cost});
                left_money[nxt.node] = cur.money - nxt.cost;
            }
        }
    }

    if (left_money[end] >= 0)
        return true;
    else
        return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll V, E, start, end, start_money;
    cin >> V >> E >> start >> end >> start_money;
    graph.resize(V + 1);
    left_money.resize(V + 1);

    for (int i = 0; i < E; i++) {
        ll s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }

    ll s = 1;
    ll e = 1000000000;
    ll mid;

    while (s <= e) {
        mid = (s + e) / 2;

        if (dijkstra(start, end, mid, start_money))
            e = mid - 1;
        else
            s = mid + 1;
    }

    if (s == 1000000001)
        cout << -1;
    else
        cout << s;
}