#include <iostream>
#include <algorithm>
#define INF 10001
using namespace std;

int dp[10001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int coin, goal, current;
    cin >> coin >> goal;

    fill(dp, dp + 10001, INF);
    dp[0] = 0;

    for (int i = 0; i < coin; i++)
    {
        cin >> current;

        for (int j = current; j <= goal; j++)
            dp[j] = min(dp[j], dp[j - current] + 1);
    }

    if (dp[goal] == INF)
        cout << -1;
    else
        cout << dp[goal];
}