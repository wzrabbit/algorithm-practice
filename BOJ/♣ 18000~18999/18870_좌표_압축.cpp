#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int arr[1000001];
int sortedArr[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        arr[i] = d;
        sortedArr[i] = d;
    }
    sort(sortedArr, sortedArr + n);

    unordered_map<int, int> compressed;
    int prev = -1000000001;
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (sortedArr[i] != prev)
        {
            prev = sortedArr[i];
            compressed[sortedArr[i]] = id++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << compressed[arr[i]] << ' ';
    }
}