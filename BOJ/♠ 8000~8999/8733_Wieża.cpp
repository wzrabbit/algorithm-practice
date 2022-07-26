#include <iostream>
#include <algorithm>
using namespace std;

int step[500001];

int binary_search(int S, int height)
{
    int start = 0;
    int end = S;
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if ((start + end) % 2 == 1)
            mid++;

        if (height > step[mid])
            start = mid;
        else
            end = mid - 1;
    }

    return end;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int S, P;
    cin >> S >> P;

    step[0] = 0;
    for (int i = 1; i <= S; i++)
    {
        cin >> step[i];
        step[i] = max(step[i - 1], step[i]);
    }

    for (int i = 1; i <= P; i++)
    {
        int cur;
        cin >> cur;

        cout << binary_search(S, cur) << ' ';
    }
}