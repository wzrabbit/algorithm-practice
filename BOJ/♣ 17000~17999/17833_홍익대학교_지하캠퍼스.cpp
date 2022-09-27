#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 2000000001
using namespace std;

struct loc {
    int node, dist;
};

bool operator<(loc a, loc b) {
    return a.dist > b.dist;
}

vector<loc> graph[2001];
int dist[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, start, end, E;
    cin >> V >> start >> end >> E;

    for (int i = 1; i <= V; i++) {
        int floor, time, left, right, gap;
        cin >> floor >> time >> left >> right;
        gap = abs(left - right);

        while (floor <= V) {
            graph[left].push_back({right, time});
            graph[right].push_back({left, time});
            floor++;
            left++;
            right++;
        }
    }

    fill(dist + 1, dist + 2001, INF);
    dist[start] = 0;
    priority_queue<loc> pq;
    pq.push({start, 0});

    while (pq.size()) {
        loc cur = pq.top();
        pq.pop();

        if (cur.dist > dist[cur.node])
            continue;

        for (size_t i = 0; i < graph[cur.node].size(); i++) {
            loc nxt = graph[cur.node][i];

            if (cur.dist + nxt.dist < dist[nxt.node]) {
                dist[nxt.node] = cur.dist + nxt.dist;
                pq.push({nxt.node, cur.dist + nxt.dist});
            }
        }
    }

    if (dist[end] == INF)
        cout << -1;
    else
        cout << dist[end];
}