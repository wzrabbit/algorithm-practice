#include <iostream>
using namespace std;
typedef long long ll;

ll factorial[250001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll len, mod;
    ll total = 0;

    cin >> len >> mod;

    factorial[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        factorial[i] = factorial[i - 1] * i % mod;
    }

    for (ll i = 1; i <= len; i++)
    {
        total += (len - i + 1) * factorial[i] % mod * factorial[len - i + 1] % mod;
        total %= mod;
    }

    cout << total;
}