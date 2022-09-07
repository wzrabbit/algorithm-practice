#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 500001
using namespace std;

struct node {
    int v, d;
};

bool operator<(node a, node b) {
    return a.d > b.d;
}

vector<node> graph[5001];
int dist[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    fill(&dist[1], &dist[V + 1], INF);

    for (int i = 0; i < E; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
        graph[e].push_back({s, d});
    }

    int start, end;
    cin >> start >> end;
    priority_queue<node> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (pq.size()) {
        node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.v]) continue;

        for (size_t i = 0; i < graph[cur.v].size(); i++) {
            node next = graph[cur.v][i];

            if (cur.d + next.d < dist[next.v]) {
                dist[next.v] = cur.d + next.d;
                pq.push({next.v, cur.d + next.d});
            }
        }
    }

    cout << dist[end];
}