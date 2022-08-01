#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int prev_max = 0;
    int cur_max = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;

        if (d == 1)
        {
            prev_max++;
            cur_max++;
            prev_max = max(prev_max, cur_max);
            cur_max = 0;
        }
        else
        {
            prev_max++;
            cur_max += 2;
        }
    }

    cout << max(prev_max, cur_max);
}