#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    ll current = 1;
    for (int i = 2; i <= n; i++)
    {
        current *= i;
        current %= 10000000;

        while (current % 10 == 0)
            current /= 10;
    }

    cout << current % 1000;
}
