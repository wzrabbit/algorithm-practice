#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    int n;
    ll d;
};

bool operator<(const Node a, const Node b) { return a.d > b.d; }

ll dist_A[200001];
ll dist_B[200001];
vector<Node> graph[200001];
int V, E, A, B;

void perform_dijkstra(ll dist[200001], int start) {
    fill(dist + 1, dist + V + 1, INF);
    priority_queue<Node> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (Node next : graph[cur.n]) {
            if (cur.d + next.d < dist[next.n]) {
                dist[next.n] = cur.d + next.d;
                pq.push({next.n, dist[next.n]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> A >> B;

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    perform_dijkstra(dist_A, A);
    perform_dijkstra(dist_B, B);

    vector<int> answer;
    ll best_dist = INF;

    for (int i = 1; i <= V; i++) {
        ll cur_dist = dist_A[i] + dist_B[i];

        if (cur_dist < best_dist) {
            answer.clear();
            best_dist = cur_dist;
        }

        if (cur_dist <= best_dist) {
            answer.push_back(i);
        }
    }

    cout << answer.size() << '\n';

    for (int cur : answer) {
        cout << cur << ' ';
    }
}
