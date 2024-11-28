#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<int> graph[123457];
ll value[123457];
ll dp[123457];
bool visited[123457];

void dfs(int cur) {
    visited[cur] = true;
    dp[cur] = value[cur];

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];

        if (visited[next]) {
            continue;
        }

        dfs(next);
        dp[cur] += dp[next];
    }

    dp[cur] = max(0ll, dp[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        char type;
        ll population, connected;
        cin >> type >> population >> connected;

        graph[connected].push_back(i);
        graph[i].push_back(connected);

        if (type == 'W') {
            population *= -1;
        }

        value[i] = population;
    }

    dfs(1);
    cout << dp[1];
}
