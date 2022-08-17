#include <iostream>
#include <algorithm>
using namespace std;

int tower_cnt[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    int left = N;

    for (int i = 0, d; i < N; i++)
    {
        cin >> d;
        tower_cnt[d]++;
    }

    int min_ = 1000000;
    for (int i = 0; i <= 1000000; i++)
    {
        left -= tower_cnt[i];
        min_ = min(min_, i + left);
    }

    cout << min_;
}