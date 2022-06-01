#include <iostream>
using namespace std;
typedef long long ll;

int recursive(ll r)
{
    if (r == 1)
        return 0;
    if (r == 2)
        return 1;

    ll div = 2;
    while (div * 2 < r)
        div *= 2;
    return 1 - recursive(r - div);
}

int main()
{
    ll n;
    cin >> n;

    cout << recursive(n);
}