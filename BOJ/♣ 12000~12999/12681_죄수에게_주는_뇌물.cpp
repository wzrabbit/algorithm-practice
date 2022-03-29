#include <iostream>
#include <algorithm>
#include <queue>
#define INF 2000000000
using namespace std;

int dp[102][102];
int prisoner[102];
int n, m;

int top_down(int start, int end)
{
    int &res = dp[start][end];
    if (res != -1)
        return res;

    if (start + 1 == end)
        return res = 0;

    res = INF;
    for (int i = start + 1; i <= end - 1; i++)
        res = min(res, top_down(start, i) + top_down(i, end));
    res += prisoner[end] - prisoner[start] - 2;

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> prisoner[i];

    sort(prisoner + 1, prisoner + m + 1);
    prisoner[0] = 0;
    prisoner[m + 1] = n + 1;

    fill(&dp[0][0], &dp[101][102], -1);
    cout << top_down(0, m + 1) << '\n';
}