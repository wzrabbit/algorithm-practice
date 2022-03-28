#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

char board[3001][3001];
ll e_count[3001][3001];
ll s_count[3001][3001];

int main()
{
    int row, col;
    ll total = 0;
    cin >> row >> col;

    for (int r = 1; r <= row; r++)
    {
        cin >> board[r] + 1;
    }

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            if (board[r][c] == 'E')
                e_count[r][c] = 1;
            e_count[r][c] += (e_count[r][c - 1] + e_count[r - 1][c] - e_count[r - 1][c - 1]) % MOD;
            if (e_count[r][c] < 0)
                e_count[r][c] += MOD;
        }
    }

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            if (board[r][c] == 'S')
                s_count[r][c] = e_count[r][c];
            s_count[r][c] += (s_count[r][c - 1] + s_count[r - 1][c] - s_count[r - 1][c - 1]) % MOD;
            if (s_count[r][c] < 0)
                s_count[r][c] += MOD;
        }
    }

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            if (board[r][c] == 'M')
            {
                total += s_count[r][c];
                total %= MOD;
            }
        }
    }

    cout << total;
}