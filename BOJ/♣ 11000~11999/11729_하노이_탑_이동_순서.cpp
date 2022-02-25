#include <iostream>
#include <cmath>
using namespace std;

void do_hanoi(int hanoi, int start, int mid, int end)
{
    if (hanoi == 1)
    {
        cout << start << ' ' << end << '\n';
        return;
    }

    do_hanoi(hanoi - 1, start, end, mid);
    do_hanoi(1, start, mid, end);
    do_hanoi(hanoi - 1, mid, start, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int count = (int)pow(2, n) - 1;
    cout << count << '\n';
    do_hanoi(n, 1, 2, 3);
}