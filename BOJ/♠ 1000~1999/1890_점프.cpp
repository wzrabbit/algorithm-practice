#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[100][100];
long long int dp[100][100] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, d;
    cin >> width;

    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            cin >> d;
            board[r][c] = d;
        }
    }

    dp[0][0] = 1;
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            if (r == width - 1 && c == width - 1)
                break;
            int v = board[r][c];
            if (r + v < width)
                dp[r + v][c] += dp[r][c];
            if (c + v < width)
                dp[r][c + v] += dp[r][c];
        }
    }

    cout << dp[width - 1][width - 1];
}