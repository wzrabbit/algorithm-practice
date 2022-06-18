#include <iostream>
typedef long long ll;
using namespace std;

ll hubo[100002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, q, x, y, z;
    ll max_vote = 0;
    ll all_vote = 0;
    cin >> n >> q;

    while (q--)
    {
        cin >> x >> y >> z;

        if (x == 1)
        {
            hubo[z] += y;
            if (z != n + 1)
            {
                if (hubo[z] > max_vote)
                    max_vote = hubo[z];

                all_vote += y;
            }
        }
        else
        {
            if (hubo[n + 1] + y > max_vote && (hubo[n + 1] + y) * n - n >= (all_vote + z))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}