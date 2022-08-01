#include <iostream>
#include <vector>
using namespace std;

vector<int> city[100001];
int dp[100001][2];
bool visited[100001];

void dfs(int cur)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (size_t i = 0; i < city[cur].size(); i++)
    {
        int next = city[cur][i];
        if (visited[next])
            continue;

        dfs(next);

        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        city[a].push_back(b);
        city[b].push_back(a);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}