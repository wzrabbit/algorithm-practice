#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

bool sieve[15000001];
ll mod = 1000000007;

ll get_pow(ll num, ll level)
{
    if (level == 0)
        return 1;

    ll before = get_pow(num, level / 2);
    long temp = before * before % mod;

    if (level % 2 == 0)
        return temp;
    else
        return num * temp % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll row, col, total = 1;
    cin >> row >> col;

    fill(sieve, sieve + 15000001, true);
    for (int i = 2; i <= (int)floor(sqrt(min(row, col))); i++)
    {
        if (sieve[i] == false)
            continue;

        for (int j = i * 2; j <= min(row, col); j += i)
            sieve[j] = false;
    }

    for (int i = 2; i <= min(row, col); i++)
    {
        if (sieve[i] == false)
            continue;
        ll karma = i;
        while (karma <= min(row, col))
        {
            total = (total * get_pow(i, (row / karma) * (col / karma))) % mod;
            karma *= i;
        }
    }

    cout << total;
}