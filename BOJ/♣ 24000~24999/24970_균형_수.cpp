#include <iostream>
#include <algorithm>
#define MOD 14348907
typedef long long ll;
using namespace std;

int dp[51][900][10];
int dp2[51][900][10];

int main()
{
    int nn;
    cin >> nn;
    int n = nn / 2;
    ll total = 45;

    for (int i = 1; i <= 9; i++)
        dp[1][i][i] = 1;

    for (int h = 2; h <= n; h++)
    {
        for (int r = 0; r <= h * 9; r++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int p = 0; p <= 9; p++)
                {
                    if (r - c >= 0)
                        dp[h][r][c] = (dp[h][r][c] + dp[h - 1][r - c][p]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++)
        dp2[1][i][i] = 1;

    for (int h = 2; h <= n; h++)
    {
        for (int r = 0; r <= h * 9; r++)
        {
            for (int c = 0; c <= 9; c++)
            {
                for (int p = 0; p <= 9; p++)
                {
                    if (r - c >= 0)
                        dp2[h][r][c] = (dp2[h][r][c] + dp2[h - 1][r - c][p]) % MOD;
                }
            }
        }
    }

    for (int i = 2; i <= nn; i++)
    {
    }

    for (int r = 0; r <= n * 9; r++)
    {
        for (int c = 0; c <= 9; c++)
            total = (total + r * dp[n][r][c] * dp2[n][r][c]) % MOD;
    }

    if (nn % 2 == 1)
        total = total * 10 % MOD;

    cout << "DP:\n";
    for (int r = 0; r <= n * 9; r++)
    {
        for (int c = 0; c <= 9; c++)
            cout << dp[n][r][c] << ' ';
        cout << '\n';
    }
    cout << '\n';
    cout << "DP2:\n";
    for (int r = 0; r <= n * 9; r++)
    {
        for (int c = 0; c <= 9; c++)
            cout << dp2[n][r][c] << ' ';
        cout << '\n';
    }
    cout << '\n';

    cout << total;
}