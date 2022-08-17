#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int dp[101][1000001];
int things[101][2];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, B;
    cin >> N >> B;

    for (int i = 1; i <= N; i++)
        cin >> things[i][0] >> things[i][1];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 1000000; j++)
        {
            dp[i][j] = max(
                dp[i - 1][j],
                (j - things[i][0] >= 0) ? dp[i - 1][j - things[i][0]] + things[i][1] : 0);
        }
    }

    ll max_up = 0, max_down = 1;
    int max_bag = 1;

    for (int i = 1; i <= B; i++)
    {
        ll cur_down;
        cin >> cur_down;
        ll cur_up = (ll)dp[N][cur_down];

        if (cur_up * max_down > cur_down * max_up)
        {
            max_bag = i;
            max_up = cur_up;
            max_down = cur_down;
        }
    }

    cout << max_bag;
}