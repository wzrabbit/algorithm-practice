#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(&arr[0], &arr[n]);
    cout << arr[k - 1];
}