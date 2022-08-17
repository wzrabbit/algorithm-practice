#include <iostream>
#include <algorithm>
#define MOD 987654321
typedef long long ll;
using namespace std;

int dp[100001][10];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = j - 2; k <= j + 2; k++)
            {
                if (k <= 0 || k >= 10)
                    continue;

                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 9; i++)
        answer = (answer + dp[N][i]) % MOD;

    cout << answer;
}