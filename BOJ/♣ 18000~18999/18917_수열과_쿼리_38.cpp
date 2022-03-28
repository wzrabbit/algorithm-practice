#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, q;
    ll n;
    ll sum_ = 0, xor_ = 0;
    cin >> t;

    while (t--)
    {
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> n;
            sum_ += n;
            xor_ ^= n;
            break;
        case 2:
            cin >> n;
            sum_ -= n;
            xor_ ^= n;
            break;
        case 3:
            cout << sum_ << '\n';
            break;
        case 4:
            cout << xor_ << '\n';
            break;
        }
    }
}