#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct e_data {
    int node, len;
};

struct q_data {
    int node, cost;
};

vector<vector<e_data>> graph;

bool can_connect(int V, int F, int limit) {
    vector<bool> visited(V + 1, false);
    deque<q_data> q;
    q.push_back({1, 0});

    while (q.size()) {
        q_data cur = q.front();
        q.pop_front();

        if (visited[cur.node])
            continue;
        else
            visited[cur.node] = true;

        if (cur.node == V) {
            if (cur.cost <= F)
                return true;
            else
                return false;
        }

        for (size_t i = 0; i < graph[cur.node].size(); i++) {
            e_data nxt = graph[cur.node][i];
            if (!visited[nxt.node]) {
                if (nxt.len > limit)
                    q.push_back({nxt.node, cur.cost + 1});
                else
                    q.push_front({nxt.node, cur.cost});
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E, F;
    cin >> V >> E >> F;

    graph.resize(V + 1);

    for (int i = 0; i < E; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        graph[s].push_back({e, l});
        graph[e].push_back({s, l});
    }

    int start = 0;
    int end = 1000000;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (can_connect(V, F, mid))
            end = mid - 1;
        else
            start = mid + 1;
    }

    if (start == 1000001)
        cout << -1;
    else
        cout << start;
}