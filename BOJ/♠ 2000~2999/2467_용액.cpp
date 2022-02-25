#include <iostream>
#include <algorithm>
using namespace std;

int liquid[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, d;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> d;
        liquid[i] = d;
    }

    int l = 0;
    int r = num - 1;
    int ans = 2000000000;
    int ansL, ansR;
    int sum_;

    while (l < r)
    {
        sum_ = liquid[l] + liquid[r];
        if (abs(sum_) < abs(ans))
        {
            ans = sum_;
            ansL = liquid[l];
            ansR = liquid[r];
        }
        if (sum_ > 0)
            r--;
        else if (sum_ < 0)
            l++;
        else
            break;
    }

    cout << ansL << ' ' << ansR << '\n';
}