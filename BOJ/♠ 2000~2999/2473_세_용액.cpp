#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long int liquid[5001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long int ans = 3000000001;
    int ansL, ansR, ansI;
    long long int sum_;
    bool isZero = false;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }

    sort(&liquid[0], &liquid[n]);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            sum_ = liquid[l] + liquid[r] + liquid[i];
            if (abs(sum_) < abs(ans))
            {
                ans = sum_;
                ansL = liquid[l];
                ansR = liquid[r];
                ansI = liquid[i];
            }
            if (sum_ > 0)
                r--;
            else if (sum_ < 0)
                l++;
            else
            {
                isZero = true;
                break;
            }
        }
        if (isZero)
            break;
    }

    cout << ansI << ' ' << ansL << ' ' << ansR;
}