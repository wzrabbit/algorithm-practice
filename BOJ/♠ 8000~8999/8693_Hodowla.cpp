#include <iostream>
#include <algorithm>
using namespace std;

int board[1002][1002];
int prefix[1002][1002];

void do_magic(int r1, int c1, int r2, int c2)
{
    prefix[r1][c1]++;
    prefix[r1][c2 + 1]--;
    prefix[r2 + 1][c1]--;
    prefix[r2 + 1][c2 + 1]++;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, Q, c1, r1, c2, r2;
    cin >> N;

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
            cin >> board[r][c];
    }

    cin >> Q;

    while (Q--)
    {
        cin >> c1 >> r1 >> c2 >> r2;
        do_magic(r1, c1, r2, c2);
    }

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
            prefix[r][c] += prefix[r][c - 1];
    }

    for (int c = 1; c <= N; c++)
    {
        for (int r = 1; r <= N; r++)
            prefix[r][c] += prefix[r - 1][c];
    }

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            if ((board[r][c] + prefix[r][c]) % 2 == 0)
                cout << "0 ";
            else
                cout << "1 ";
        }
        cout << '\n';
    }
}