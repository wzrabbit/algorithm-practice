#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;
typedef long long ll;

ll loc[1001];
ll elec[1001];
ll dp[2][1001][1001];
int n, s;

ll top_down(int dir, int start, int end)
{
    ll &current = dp[dir][start][end];
    ll temp;
    if (current != -1)
        return current;

    if (dir == 0)
    {
        if (start < s)
        {
            current = top_down(0, start + 1, end) + (elec[n] - (elec[end] - elec[start])) * (loc[start + 1] - loc[start]);
        }

        temp = top_down(1, start, end) + (elec[n] - (elec[end] - elec[start - 1])) * (loc[end] - loc[start]);

        if (current == -1 || current > temp)
            current = temp;
    }
    else
    {
        if (end > s)
        {
            current = top_down(1, start, end - 1) + (elec[n] - (elec[end - 1] - elec[start - 1])) * (loc[end] - loc[end - 1]);
        }

        temp = top_down(0, start, end) + (elec[n] - (elec[end] - elec[start - 1])) * (loc[end] - loc[start]);

        if (current == -1 || current > temp)
            current = temp;
    }

    return current;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> loc[i];
        cin >> elec[i];
        elec[i] += elec[i - 1];
    }

    fill(&dp[0][0][0], &dp[1][1000][1001], -1);
    dp[0][s][s] = 0;

    cout << top_down(1, 1, n);
}