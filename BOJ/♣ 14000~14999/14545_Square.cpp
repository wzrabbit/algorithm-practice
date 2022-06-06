#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll answer = 0;

        for (ll i = 1; i <= n; i++)
            answer += i * i;

        cout << answer << '\n';
    }
}