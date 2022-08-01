#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int visited[100001];
int dp[100001];

void dfs(int cur)
{
    visited[cur] = true;
    dp[cur] = 1;

    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];

        if (visited[next])
            continue;

        dfs(next);
        dp[cur] += dp[next];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(R);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
}