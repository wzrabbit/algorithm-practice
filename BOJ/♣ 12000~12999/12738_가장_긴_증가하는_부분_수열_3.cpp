#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int longest = 1;
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

        longest = max(end + 1, longest);
        dp[end + 1] = min(arr[i], dp[end + 1]);
    }

    cout << longest << '\n';
}