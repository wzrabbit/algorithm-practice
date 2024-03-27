#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define INF 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

vector<ll> graph[100001];
map<ll, ll> cost;
ll dp[100001];
bool visited[100001];

ll tree_dp(ll cur) {
    visited[cur] = true;
    ll cost_sum = 0;

    for (size_t i = 0; i < graph[cur].size(); i++) {
        ll nxt = graph[cur][i];

        if (!visited[nxt]) {
            cost_sum += min(cost[cur * 100'000 + nxt], tree_dp(nxt));
        }
    }

    if (cost_sum == 0) {
        return dp[cur] = INF;
    }

    return dp[cur] = cost_sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u * 100'000 + v] = d;
        cost[v * 100'000 + u] = d;
    }

    cout << tree_dp(1);
}
