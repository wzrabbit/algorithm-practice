#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_, ans;
    cin >> max_;
    ans = 0;

    for (int i = 1; i < n; i++)
    {
        int current;
        cin >> current;

        if (current > max_)
            max_ = current;
        if (max_ - current > ans)
            ans = max_ - current;
    }

    cout << ans;
}