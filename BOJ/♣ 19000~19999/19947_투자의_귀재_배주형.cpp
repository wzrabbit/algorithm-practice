#include <iostream>
#include <algorithm>
#include <cmath>
#include <initializer_list>
using namespace std;

int dp[11];

int main()
{
    int money, year;
    cin >> money >> year;

    dp[0] = money;
    for (int i = 1; i <= 10; i++)
        dp[i] = (int)floor(max({dp[i - 1] * 1.05,
                                (i >= 3) ? dp[i - 3] * 1.2 : 0,
                                (i >= 5) ? dp[i - 5] * 1.35 : 0}));

    cout << dp[year];
}