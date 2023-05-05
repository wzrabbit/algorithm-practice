#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define INF 2'000'000'000'000'001
typedef long long ll;
using namespace std;

struct Next {
    ll no, cost;
};

struct PQData {
    ll no;
    ll dist;
};

bool operator<(PQData a, PQData b) {
    return a.dist > b.dist;
}

ll edge[100001][2];
set<ll> raw_vertex;
map<ll, ll> height_to_no;
map<ll, ll> no_to_height;
vector<Next> graph[200001];
ll dist[200001];
ll best_dist = INF;
ll V, H;

void generate_graph() {
    ll no = 0;
    ll prev;

    for (auto it = raw_vertex.begin(); it != raw_vertex.end(); it++) {
        height_to_no[*it] = ++no;
        no_to_height[no] = *it;

        if (it != raw_vertex.begin()) {
            ll gap = *it - prev;
            graph[no].push_back({no - 1, gap});
        }

        prev = *it;
    }

    for (int i = 1; i <= V; i++) {
        ll start = height_to_no[edge[i][0]];
        ll end = height_to_no[edge[i][0] + edge[i][1]];
        ll gap = edge[i][1];

        graph[start].push_back({end, gap});
    }
}

void traverse() {
    if (no_to_height[1] != 0) {
        return;
    }

    fill(dist + 1, dist + V * 2 + 1, INF);

    priority_queue<PQData> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        if (cur.dist > dist[cur.no]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.no].size(); i++) {
            Next next = graph[cur.no][i];

            if (cur.dist + next.cost < dist[next.no]) {
                dist[next.no] = cur.dist + next.cost;
                pq.push({next.no, cur.dist + next.cost});
            }

            if (no_to_height[next.no] >= H) {
                best_dist = min(best_dist, cur.dist + H - no_to_height[cur.no]);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> H;

    for (int i = 1; i <= V; i++) {
        cin >> edge[i][0] >> edge[i][1];
        raw_vertex.insert(edge[i][0]);
        raw_vertex.insert(edge[i][0] + edge[i][1]);
    }

    generate_graph();
    traverse();

    if (best_dist < INF) {
        cout << best_dist;
    } else {
        cout << "Ducks can't fly";
    }
}