#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[81][81];
ll prefix[81];
ll student[81];

ll top_down(int start, int end)
{
    ll &conflict = dp[start][end];

    if (conflict != -1)
        return conflict;

    conflict = 0;

    for (int i = start; i < end; i++)
    {
        ll current = top_down(start, i) + top_down(i + 1, end);
        if ((prefix[i] - prefix[start - 1]) * (prefix[end] - prefix[i]) < 0)
            current += abs((prefix[i] - prefix[start - 1]) * (prefix[end] - prefix[i]));

        if (current > conflict)
            conflict = current;
    }

    return conflict;
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> student[i];
        prefix[i] = student[i] + prefix[i - 1];
    }

    fill(&dp[1][1], &dp[n][n + 1], -1);
    cout << top_down(1, n) * -1;
}