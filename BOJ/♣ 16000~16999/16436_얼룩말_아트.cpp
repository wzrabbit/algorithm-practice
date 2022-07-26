#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rect_board[2503][2503];
int dia_board[2503][2503];

void draw_rect(int R, int C, int start_c, int start_r, int end_c, int end_r)
{
    rect_board[start_r][start_c]++;
    rect_board[start_r][end_c + 1]--;
    rect_board[end_r + 1][start_c]--;
    rect_board[end_r + 1][end_c + 1]++;
}

void draw_dia(int R, int C, int mid_c, int mid_r, int radius)
{
    dia_board[mid_r - radius][mid_c]++;
    dia_board[mid_r - radius + 1][mid_c]++;
    dia_board[mid_r + radius + 1][mid_c]++;
    dia_board[mid_r + radius + 2][mid_c]++;
    dia_board[mid_r + 1][mid_c - radius - 1]--;
    dia_board[mid_r + 1][mid_c - radius]--;
    dia_board[mid_r + 1][mid_c + radius]--;
    dia_board[mid_r + 1][mid_c + radius + 1]--;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int C, R, Q, a, b, c, d, e;
    cin >> C >> R >> Q;

    while (Q--)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b >> c >> d >> e;
            b++;
            c++;
            d++;
            e++;
            draw_rect(R, C, b, c, d, e);
        }
        else
        {
            cin >> b >> c >> d;
            b++;
            c++;
            draw_dia(R, C, b, c, d);
        }
    }

    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
            rect_board[r][c] += rect_board[r][c - 1];
    }

    for (int c = 1; c <= C; c++)
    {
        for (int r = 1; r <= R; r++)
            rect_board[r][c] += rect_board[r - 1][c];
    }

    for (int i = 1; i <= C; i++)
    {
        int r = 1;
        int c = i;
        while (r <= R + 1 && c >= 0)
        {
            dia_board[r][c] += dia_board[r - 1][c + 1];
            r++;
            c--;
        }
    }

    for (int i = 2; i <= R; i++)
    {
        int r = i;
        int c = C;
        while (r <= R + 1 && c >= 0)
        {
            dia_board[r][c] += dia_board[r - 1][c + 1];
            r++;
            c--;
        }
    }

    for (int i = 1; i <= C; i++)
    {
        int r = 1;
        int c = i;
        while (r <= R + 1 && c <= C + 1)
        {
            dia_board[r][c] += dia_board[r - 1][c - 1];
            r++;
            c++;
        }
    }

    for (int i = 2; i <= R; i++)
    {
        int r = i;
        int c = 1;
        while (r <= R + 1 && c <= C + 1)
        {
            dia_board[r][c] += dia_board[r - 1][c - 1];
            r++;
            c++;
        }
    }

    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            if ((rect_board[r][c] + dia_board[r][c]) % 2 == 0)
                cout << '.';
            else
                cout << '#';
        }
        cout << '\n';
    }
}