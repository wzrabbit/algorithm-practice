#include <iostream>
#include <algorithm>
using namespace std;

int board[500][500];
int dp[500][500];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int width;
int max_ = 1;

int traverse(int ro, int co)
{
    if (dp[ro][co] >= 0)
        return dp[ro][co];
    dp[ro][co] = 0;

    for (int i = 0; i <= 3; i++)
    {
        int r = ro + dr[i];
        int c = co + dc[i];

        if (r >= 0 && r < width && c >= 0 && c < width && board[ro][co] < board[r][c])
        {
            dp[ro][co] = max(dp[ro][co], traverse(r, c));
        }
    }
    dp[ro][co] += 1;
    if (max_ < dp[ro][co])
        max_ = dp[ro][co];
    return dp[ro][co];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> width;

    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            cin >> n;
            board[r][c] = n;
            dp[r][c] = -1;
        }
    }

    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            traverse(r, c);
        }
    }

    cout << max_ << '\n';
}