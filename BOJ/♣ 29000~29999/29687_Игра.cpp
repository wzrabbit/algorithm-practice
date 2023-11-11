#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1'000'000'000'000'001
typedef long long ll;
using namespace std;

struct Node {
    int n;
    ll d;
};

bool operator<(const Node& a, const Node& b) {
    return a.d > b.d;
}

vector<Node> graph[100001];
ll dist[100001];
int V, E;

void dijkstra(int start) {
    fill(dist + 1, dist + V + 1, INF);
    dist[start] = 0;

    priority_queue<Node> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            int next_node = graph[cur.n][i].n;
            ll next_dist = cur.d + graph[cur.n][i].d;

            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_node, next_dist});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int s, e;
        ll d;
        cin >> s >> e >> d;

        graph[s].push_back({e, d});
        graph[e].push_back({s, d});
    }

    int A, B, F;
    cin >> A >> B >> F;

    dijkstra(F);

    if (dist[A] <= dist[B]) {
        cout << "First";
    } else {
        cout << "Second";
    }
}