#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll num[200001];
ll dp[200001];
ll n, goal, _max;

bool work(int limit)
{
    _max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - limit - 1 > 0 && _max < dp[i - limit - 1])
            _max = dp[i - limit - 1];

        dp[i] = _max + num[i];

        if (dp[i] >= goal)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> goal;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        if (num[i] >= goal)
        {
            cout << "Free!";
            return 0;
        }
    }

    int start = 0;
    int end = n - 2;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (work(mid))
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}