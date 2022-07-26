#include <iostream>
#include <algorithm>
#include <initializer_list>
typedef long long ll;
using namespace std;

ll board[51][51];
ll prefix[51][51];

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    ll max_ = 0;

    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            scanf("%1lld", &board[r][c]);
            prefix[r][c] = board[r][c] + prefix[r - 1][c] +
                           prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    if (R >= 3)
    {
        for (int i = 1; i <= R - 2; i++)
        {
            for (int j = i + 1; j <= R - 1; j++)
            {
                ll calc = (prefix[i][C]) *
                          (prefix[j][C] - prefix[i][C]) *
                          (prefix[R][C] - prefix[j][C]);

                if (calc > max_)
                    max_ = calc;
            }
        }
    }

    if (C >= 3)
    {
        for (int i = 1; i <= C - 2; i++)
        {
            for (int j = i + 1; j <= C - 1; j++)
            {
                ll calc = (prefix[R][i]) *
                          (prefix[R][j] - prefix[R][i]) *
                          (prefix[R][C] - prefix[R][j]);

                if (calc > max_)
                    max_ = calc;
            }
        }
    }

    for (int r = 1; r < R; r++)
    {
        for (int c = 1; c < C; c++)
        {
            ll w, x, y, z;

            w = prefix[r][c];
            x = prefix[r][C] - w;
            y = prefix[R][c] - w;
            z = prefix[R][C] - w - x - y;

            ll calc = max({(w + x) * y * z,
                           (w + y) * x * z,
                           (x + z) * w * y,
                           (y + z) * w * x});

            if (calc > max_)
                max_ = calc;
        }
    }

    printf("%lld", max_);
}