#include <iostream>
#include <algorithm>
using namespace std;

int input[1000][1000];
int dp[1000][1000];
int _left[1000];
int _right[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> row >> col;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> input[r][c];
        }
    }

    dp[0][0] = input[0][0];
    for (int c = 1; c < col; c++)
        dp[0][c] = dp[0][c - 1] + input[0][c];

    for (int r = 1; r < row; r++)
    {
        _left[0] = dp[r - 1][0] + input[r][0];
        _right[col - 1] = dp[r - 1][col - 1] + input[r][col - 1];
        for (int c = 1; c < col; c++)
            _left[c] = max(_left[c - 1], dp[r - 1][c]) + input[r][c];
        for (int c = col - 2; c >= 0; c--)
            _right[c] = max(_right[c + 1], dp[r - 1][c]) + input[r][c];
        for (int c = 0; c < col; c++)
            dp[r][c] = max(_left[c], _right[c]);
    }

    cout << dp[row - 1][col - 1];
}