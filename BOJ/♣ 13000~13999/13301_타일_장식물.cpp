#include <iostream>

using namespace std;

int main()
{
    long long input;
    long long dp[81] = {
        -1,
        1,
        1,
    };
    cin >> input;

    for (int i = 3; i <= input; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    if (input == 1)
    {
        cout << 4;
    }
    else if (input == 2)
    {
        cout << 6;
    }
    else if (input == 3)
    {
        cout << 10;
    }
    else
    {
        cout << dp[input] * 3 + dp[input - 1] * 2 + dp[input - 2] * 2 + dp[input - 3];
    }
}