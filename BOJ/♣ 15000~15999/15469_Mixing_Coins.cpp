#include <iostream>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;

struct coin
{
    char group;
    ll amount;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        deque<coin> d;
        stack<coin> s;

        for (int i = 0; i < N; i++)
        {
            char group;
            ll amount;
            cin >> group >> amount;
            d.push_back({group, amount});
        }

        while (d.size())
        {
            coin cur = d.front();
            d.pop_front();

            if (s.size() > 0)
            {
                coin old = s.top();

                if (cur.group == old.group)
                {
                    s.pop();
                    cur.amount += old.amount;
                }
            }

            ll rem = cur.amound % 3;
            cur.amount /= 3;

            if (d.size() > 0 && cur.amount > 0)
            {
                coin prev = d.back();

                if (cur.group == prev.group)
                {
                    d.pop_back();
                    cur.amount += prev.amount;
                }
            }

            if (cur.amount > 0)
                d.push_back(cur);

            if (rem > 0)
                s.push({cur.group, rem});
        }

        ll total = 0;
        while (s.size())
        {
            coin cur = s.top();
            s.pop();

            total += cur.amount;
        }

        cout << total << '\n';
    }
}