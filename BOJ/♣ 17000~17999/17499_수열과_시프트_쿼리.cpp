#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, query, n, q, idx, x;
    int shifter = 0;
    deque<int> arr;
    cin >> num >> query;

    for (int i = 0; i < num; i++)
    {
        cin >> n;
        arr.push_back(n);
    }

    while (query--)
    {
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> idx >> x;
            idx = (idx - shifter - 1) % num;
            if (idx < 0)
                idx += num;
            arr[idx] += x;
            break;
        case 2:
            cin >> x;
            shifter += x;
            if (shifter >= num)
                shifter %= num;
            break;
        case 3:
            cin >> x;
            shifter -= x;
            if (shifter < 0)
                shifter = shifter % num + num;
            break;
        }
    }

    if (shifter > 0)
    {
        for (int i = 0; i < shifter; i++)
        {
            int temp = arr.back();
            arr.pop_back();
            arr.push_front(temp);
        }
    }
    else
    {
        for (int i = shifter; i < 0; i++)
        {
            int temp = arr.front();
            arr.pop_front();
            arr.push_back(temp);
        }
    }

    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << ' ';
    }
}