#include <iostream>
#include <initializer_list>
#include <algorithm>
using namespace std;

int arr[1001];
int upper[1001];
int lower[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int longest = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    fill(upper, upper + n, 1);
    fill(lower, lower + n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                upper[i] = max(upper[j] + 1, upper[i]);
            else if (arr[i] < arr[j])
                lower[i] = max({upper[j] + 1, lower[j] + 1, lower[i]});
        }
        longest = max({upper[i], lower[i], longest});
    }

    cout << longest << '\n';
}