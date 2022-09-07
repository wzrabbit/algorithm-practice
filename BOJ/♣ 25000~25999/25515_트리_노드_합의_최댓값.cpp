#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> graph[100000];
ll value[100000];
ll dp[100000];
bool visited[100000];

void dfs(ll cur) {
    visited[cur] = true;
    dp[cur] = value[cur];

    for (int i = 0; i < graph[cur].size(); i++) {
        ll next = graph[cur][i];

        if (visited[next])
            continue;

        dfs(next);
        if (dp[next] > 0)
            dp[cur] += dp[next];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
        cin >> value[i];

    dfs(0);
    cout << dp[0];
}