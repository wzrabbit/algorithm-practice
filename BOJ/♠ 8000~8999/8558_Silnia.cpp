#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans[5] = {1, 1, 2, 6, 4};

    if (N >= 5)
        cout << 0;
    else
        cout << ans[N];
}