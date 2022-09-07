#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct n_data {
    int node, cost;
};

struct pq_data {
    int node, money;
};

bool operator<(pq_data a, pq_data b) {
    return a.money < b.money;
}

vector<vector<n_data>> graph;
vector<int> left_money;

bool dijkstra(int start, int end, int limit, int start_money) {
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

    int V, E, start, end, start_money;
    cin >> V >> E >> start >> end >> start_money;
    graph.resize(V + 1);
    left_money.resize(V + 1);
    bool success = false;

    for (int i = 0; i < E; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }

    for (int i = 1; i <= 20; i++) {
        if (dijkstra(start, end, i, start_money)) {
            cout << i;
            success = true;
            break;
        }
    }

    if (!success)
        cout << -1;
}