#include <iostream>
using namespace std;
typedef long long ll;

ll dp[10001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        ll goal, mod;
        cin >> goal >> mod;

        dp[1] = 1 % mod;
        dp[2] = 1 % mod;

        for (auto i = 3; i <= goal; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

        cout << "Case #" << t << ": " << dp[goal] << '\n';
    }
}