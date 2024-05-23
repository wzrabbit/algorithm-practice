#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1'000'000'000'000'001
#define MOD 1'000'000'009
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

bool operator<(const Node &a, const Node &b) {
    return a.d > b.d;
}

vector<Node> graph[100001];
vector<ll> history[100001];
ll dist[100001];
ll dp[100001];
ll N, M, S, E;

void perform_dijkstra() {
    priority_queue<Node> pq;
    pq.push({S, 0});
    dist[S] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            ll next_node = graph[cur.n][i].n;
            ll next_dist = graph[cur.n][i].d;

            if (cur.d + next_dist == dist[next_node]) {
                history[next_node].push_back(cur.n);
                continue;
            }

            if (cur.d + next_dist < dist[next_node]) {
                history[next_node].clear();
                history[next_node].push_back(cur.n);
                dist[next_node] = cur.d + next_dist;
                pq.push({next_node, cur.d + next_dist});
            }
        }
    }
}

ll get_shortest_path_count(ll cur) {
    if (dp[cur] != -1) {
        return dp[cur];
    }

    ll path_count = 0;

    for (size_t i = 0; i < history[cur].size(); i++) {
        path_count = (path_count + get_shortest_path_count(history[cur][i])) % MOD;
    }

    return dp[cur] = path_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> S >> E;

    for (int i = 1; i <= M; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    fill(dist + 1, dist + N + 1, INF);
    fill(dp + 1, dp + N + 1, -1);
    dp[S] = 1;

    perform_dijkstra();
    cout << get_shortest_path_count(E);
}