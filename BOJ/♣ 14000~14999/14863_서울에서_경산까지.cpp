#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100002];

int main()
{
    int n, limit, m1, p1, m2, p2;
    int max_ = 0;
    cin >> n >> limit;

    fill(&dp[0][0], &dp[n][limit + 1], -1);
    dp[0][0] = 0;

    for (int r = 1; r <= n; r++)
    {
        cin >> m1 >> p1 >> m2 >> p2;

        for (int c = m1; c <= limit; c++)
        {
            if (dp[r - 1][c - m1] != -1 && dp[r][c] < dp[r - 1][c - m1] + p1)
                dp[r][c] = dp[r - 1][c - m1] + p1;
        }

        for (int c = m2; c <= limit; c++)
        {
            if (dp[r - 1][c - m2] != -1 && dp[r][c] < dp[r - 1][c - m2] + p2)
                dp[r][c] = dp[r - 1][c - m2] + p2;
        }
    }

    for (int i = 0; i <= limit; i++)
        if (max_ < dp[n][i] && dp[n][i] != -1)
            max_ = dp[n][i];

    cout << max_;
}