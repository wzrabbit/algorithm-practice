#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[101];

int get_lis(int N, int gap)
{
    fill(&dp[1], &dp[101], 0);

    for (int i = 0; i < N; i++)
    {
        if (arr[i] - gap <= 0 || arr[i] - gap > 100)
            dp[arr[i]] = 1;
        else
            dp[arr[i]] = dp[arr[i] - gap] + 1;
    }

    int max_ = 0;
    for (int i = 1; i <= 100; i++)
        max_ = max(max_, dp[i]);

    return max_;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    int answer = 1;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = -99; i <= 99; i++)
        answer = max(answer, get_lis(N, i));

    cout << answer;
}