#include <iostream>
#include <algorithm>
using namespace std;

int dp[52][500002];
int block[52];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> block[i];

    fill(&dp[0][0], &dp[51][500001], -1);
    dp[0][0] = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= 500000; j++)
        {
            if (dp[i][j] != -1)
            {
                dp[i + 1][j + block[i + 1]] = max(dp[i][j] + block[i + 1], dp[i + 1][j + block[i + 1]]);
                dp[i + 1][abs(j - block[i + 1])] = max(dp[i][j] + block[i + 1], dp[i + 1][abs(j - block[i + 1])]);
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
            }
        }
    }

    if (dp[n][0] == 0)
        cout << -1;
    else
        cout << dp[n][0] / 2;
}