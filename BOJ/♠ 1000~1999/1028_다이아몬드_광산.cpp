#include <iostream>
#include <algorithm>
using namespace std;

int mine[752][752];
int dpA[752][752];
int dpB[752][752];
int dpC[752][752];
int dpD[752][752];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> row >> col;

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            char v;
            cin >> v;
            mine[r][c] = v == '1' ? 1 : 0;
        }
    }

    for (int r = 0; r <= row + 1; r++)
    {
        dpA[r][0] = 0;
        dpB[r][0] = 0;
        dpC[r][0] = 0;
        dpD[r][0] = 0;
    }

    for (int c = 0; c <= col + 1; c++)
    {
        dpA[0][c] = 0;
        dpB[0][c] = 0;
        dpC[0][c] = 0;
        dpD[0][c] = 0;
    }

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            if (mine[r][c] == 1)
            {
                dpA[r][c] = dpA[r - 1][c - 1] + 1;
                dpB[r][c] = dpB[r - 1][c + 1] + 1;
            }
            else
            {
                dpA[r][c] = 0;
                dpB[r][c] = 0;
            }
        }
    }

    for (int r = row; r >= 1; r--)
    {
        for (int c = 1; c <= col; c++)
        {
            if (mine[r][c] == 1)
            {
                dpC[r][c] = dpC[r + 1][c - 1] + 1;
                dpD[r][c] = dpD[r + 1][c + 1] + 1;
            }
            else
            {
                dpC[r][c] = 0;
                dpD[r][c] = 0;
            }
        }
    }

    int diamond = 0;

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            for (int d = diamond + 1; d <= min(dpC[r][c], dpD[r][c]); d++)
            {
                if (r + d * 2 - 2 > row)
                    break;
                if (min(dpA[r + d * 2 - 2][c], dpB[r + d * 2 - 2][c]) >= d)
                    diamond = d;
            }
        }
    }

    cout << diamond;
    return 0;
}