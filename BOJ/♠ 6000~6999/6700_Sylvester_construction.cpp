#include <iostream>
using namespace std;
typedef long long ll;

int recursion(ll r, ll c, ll n)
{
    if (r == 0 && c == 0)
        return 1;

    if (r >= n && c >= n)
        return -1 * recursion(r % n, c % n, n / 2);
    else
        return recursion(r % n, c % n, n / 2);
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll lv, c_start, r_start, c_width, r_width;
        cin >> lv >> c_start >> r_start >> c_width >> r_width;

        for (ll r = r_start; r < r_start + r_width; r++)
        {
            for (ll c = c_start; c < c_start + c_width; c++)
                cout << recursion(r, c, lv / 2) << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}