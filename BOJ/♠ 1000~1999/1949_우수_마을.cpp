#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10001];
int people[10001];
int dp[10001][2];
bool visited[10001];

void dfs(int cur)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = people[cur];

    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];

        if (visited[next])
            continue;

        dfs(next);
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> people[i];

    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}