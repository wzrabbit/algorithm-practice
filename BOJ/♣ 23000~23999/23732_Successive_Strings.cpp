#include <iostream>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string str;
    ll count = 0;
    int state = 0;
    int l = 0;
    int r = 0;

    cin >> N >> str;

    while (true)
    {
        if (state > 0)
        {
            count += N - r;
            if (str[l] == str[l + 1])
                state--;
            l++;
        }
        else
        {
            if (r != N - 1)
            {
                if (str[r] == str[r + 1])
                    state++;
                r++;
            }
            else
                break;
        }
    }

    cout << count;
}