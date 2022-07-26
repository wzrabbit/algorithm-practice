#include <iostream>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll get_inverse(ll x, ll y)
{
    if (y == 1)
        return x % MOD;

    ll prev = get_inverse(x, y / 2);

    if (y % 2 == 1)
        return prev * prev % MOD * x % MOD;
    else
        return prev * prev % MOD;
}

int main()
{
    ll N, K;
    cin >> N >> K;

    ll A = 1;
    for (ll i = N - K + 1; i <= N; i++)
        A = (A * i) % MOD;

    ll B = 1;
    for (ll i = 1; i <= K; i++)
        B = (B * i) % MOD;
    B = get_inverse(B, MOD - 2);

    cout << A * B % MOD;
}