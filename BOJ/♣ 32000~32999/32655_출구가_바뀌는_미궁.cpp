#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

bool operator<(const Node& a, const Node& b) { return a.d > b.d; }

vector<Node> graph[200001];
vector<ll> exits;
ll dist[200001];
int V, E, K, X;

void perform_dijkstra() {
    fill(dist + 1, dist + V + 1, INF);
    priority_queue<Node> pq;
    pq.push({1, 0});
    dist[1] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) continue;

        for (Node nxt : graph[cur.n]) {
            if (dist[nxt.n] > cur.d + nxt.d) {
                dist[nxt.n] = cur.d + nxt.d;
                pq.push({nxt.n, dist[nxt.n]});
            }
        }
    }
}

ll get_answer() {
    ll answer = INF;

    for (ll i = 0; i < X; i++) {
        ll cur_dist = dist[exits[i]];
        ll div = cur_dist / K % X;
        ll diff = (div > i) ? X - (div - i) : i - div;
        ll wait_dist = (cur_dist / K + diff) * K;

        ll cur_answer = max(cur_dist, wait_dist);
        answer = min(answer, cur_answer);
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> K;

    for (int i = 1; i <= E; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cin >> X;
    exits.resize(X);

    for (int i = 0; i < X; i++) {
        ll cur;
        cin >> cur;

        exits[i] = cur;
    }

    perform_dijkstra();
    cout << get_answer();
}
