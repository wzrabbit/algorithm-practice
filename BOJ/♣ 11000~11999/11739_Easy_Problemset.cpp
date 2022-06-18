#include <iostream>
#include <algorithm>
using namespace std;

int board[10][15];

int main()
{
    int n, q, l;
    cin >> n >> q;

    fill(&board[0][0], &board[9][14], 50);

    for (int r = 0; r < n; r++)
    {
        int l;
        cin >> l;

        for (int c = 0; c < l; c++)
            cin >> board[r][c];
    }

    int total = 0;
    int cnt = 0;
    bool kill = false;

    for (int c = 0; c < 14; c++)
    {
        for (int r = 0; r < n; r++)
        {
            if (board[r][c] >= total)
            {
                total += board[r][c];
                cnt++;
            }

            if (cnt == q)
            {
                kill = true;
                break;
            }
        }

        if (kill)
            break;
    }

    if (!kill)
        total += (q - cnt) * 50;

    cout << total;
}