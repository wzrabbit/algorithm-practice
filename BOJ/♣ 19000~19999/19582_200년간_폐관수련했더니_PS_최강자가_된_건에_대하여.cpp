#include <iostream>
#include <algorithm>
using namespace std;

const long long inf = 1000000000000001;
long long dp[2][100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0], &dp[1][100001], inf);
    dp[0][0] = 0;

    int num, limit, award;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cin >> limit >> award;

        if (dp[0][i - 1] <= limit)
            dp[0][i] = dp[0][i - 1] + award;
        if (dp[0][i - 1] != inf)
            dp[1][i] = dp[0][i - 1];

        if (dp[1][i - 1] <= limit)
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + award);
    }

    if (dp[1][num] == inf)
        cout << "Zzz";
    else
        cout << "Kkeo-eok";
}