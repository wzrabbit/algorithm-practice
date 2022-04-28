#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, m;
    deque<int> dq;
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    while (dq.size())
    {
        for (int i = 0; i < m; i++)
        {
            if (!dq.size())
                break;

            for (int j = 0; j < k - 1; j++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << '\n';
            dq.pop_front();
        }

        for (int i = 0; i < m; i++)
        {
            if (!dq.size())
                break;

            for (int j = 0; j < k - 1; j++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << '\n';
            dq.pop_back();
        }
    }
}