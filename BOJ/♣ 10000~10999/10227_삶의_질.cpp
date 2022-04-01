#include <iostream>
#include <algorithm>
using namespace std;

int row, col, height, width;
int board[3001][3001];
int state[3001][3001];
int state_total[3001][3001];

bool search(int num)
{
    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            if (board[r][c] > num)
                state[r][c] = 1;
            else if (board[r][c] < num)
                state[r][c] = -1;
            else
                state[r][c] = 0;

            state_total[r][c] = state[r][c] + state_total[r - 1][c] +
                                state_total[r][c - 1] - state_total[r - 1][c - 1];
        }
    }

    for (int r = height; r <= row; r++)
    {
        for (int c = width; c <= col; c++)
        {
            if (state_total[r][c] - state_total[r - height][c] - state_total[r][c - width] + state_total[r - height][c - width] <= 0)
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col >> height >> width;
    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
            cin >> board[r][c];
    }

    int start = 1;
    int end = row * col;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (search(mid))
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << start;
}