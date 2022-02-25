#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string small, big;
    int cnt = 0;
    int b = 0;
    cin >> small >> big;

    while (b < big.length())
    {
        int max_ = 0;
        for (int s = 0; s < small.length(); s++)
        {
            if (small[s] == big[b])
            {
                int current = 1;
                int s_ = s + 1;
                int b_ = b + 1;
                while (s_ < small.length() && b_ < big.length())
                {
                    if (small[s_] == big[b_])
                        current++;
                    else
                        break;
                    s_++;
                    b_++;
                }
                if (current > max_)
                    max_ = current;
            }
        }
        b += max_;
        cnt += 1;
    }

    cout << cnt;
}