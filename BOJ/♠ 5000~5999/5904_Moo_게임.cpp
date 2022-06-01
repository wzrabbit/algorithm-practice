#include <iostream>
using namespace std;

char moo[5] = {'_', 'm', 'o', 'o'};

char recursive(int n, int len, int mid)
{
    if (n <= 3)
        return moo[n];

    if (n <= len)
        return recursive(n, (len - mid + 1) / 2, mid - 1);

    if (n >= len && n <= len + mid)
    {
        if (n == len + 1)
            return 'm';
        else
            return 'o';
    }

    return recursive(n - len - mid, (len - mid + 1) / 2, mid - 1);
}

int main()
{
    int n, start_len = 3, mid = 4;
    cin >> n;

    while (start_len * 2 + mid <= n)
    {
        start_len = start_len * 2 + mid;
        mid++;
    }

    cout << recursive(n, start_len, mid);
}