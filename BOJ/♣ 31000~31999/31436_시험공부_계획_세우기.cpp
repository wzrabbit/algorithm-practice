#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MOD 998'244'353
typedef long long ll;
using namespace std;

ll dp[100001];
vector<ll> graph[1001];
ll weight[1001];
ll priority[1001];
ll N, X, Y;

void update_weight() {
    queue<ll> q;

    for (int i = 1; i <= N; i++) {
        if (priority[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (size_t i = 0; i < graph[cur].size(); i++) {
            int nxt = graph[cur][i];

            priority[nxt] -= 1;
            weight[nxt] += weight[cur];

            if (priority[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
}

void handle_cycles() {
    for (int i = 1; i <= N; i++) {
        if (priority[i] == 0) {
            continue;
        }

        ll cur = i;
        priority[i] = 0;

        while (true) {
            cur = graph[cur][0];

            if (cur == i) {
                break;
            }

            weight[i] += weight[cur];
            weight[cur] = 0;
            priority[cur] = 0;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> X >> Y;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (i != cur) {
            graph[i].push_back(cur);
            priority[cur] += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }

    update_weight();
    handle_cycles();

    dp[0] = 1;

    for (int n = 1; n <= N; n++) {
        if (weight[n] == 0) {
            continue;
        }

        for (int i = weight[n]; i <= Y; i++) {
            dp[i] = (dp[i] + dp[i - weight[n]]) % MOD;
        }
    }

    ll answer = 0;

    for (int i = X; i <= Y; i++) {
        answer = (answer + dp[i]) % MOD;
    }

    cout << answer;
}
