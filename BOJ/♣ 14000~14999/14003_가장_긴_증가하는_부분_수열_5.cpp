#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int dp[1000001];
int dpOrigin[1000001] = {};
int history[1000001] = {};

void printHistory(int hist)
{
    if (history[hist] != 0)
        printHistory(history[hist]);
    cout << arr[hist] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int longest = 1;
    int longestElement = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    fill(dp + 1, dp + n, 1000000001);
    dp[0] = -1000000001;

    for (int i = 1; i <= n; i++)
    {
        int start = 0;
        int end = n - 1;
        int mid;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (dp[mid] < arr[i])
                start = mid + 1;
            else
                end = mid - 1;
        }

        history[i] = dpOrigin[end];
        if (longest < end + 1)
        {
            longest = end + 1;
            longestElement = i;
        }
        if (dp[end + 1] > arr[i])
        {
            dp[end + 1] = arr[i];
            dpOrigin[end + 1] = i;
        }
    }

    cout << longest << '\n';
    printHistory(longestElement);
}