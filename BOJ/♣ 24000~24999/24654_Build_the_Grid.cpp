#include <iostream>
#include <algorithm>
using namespace std;

char grid[501][501];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void draw(int r, int c, int N)
{
    int speed = 1;
    int pos = 0;
    grid[r][c] = 'B';

    while (true)
    {
        for (int i = 0; i < speed; i++)
        {
            r += dr[pos];
            c += dc[pos];

            if (r < 0 || r >= N || c < 0 || c >= N)
                return;

            grid[r][c] = 'B';
        }

        pos = (pos + 1) % 4;
        speed++;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, r, c;
    cin >> N;

    if (N % 4 == 0)
        r = c = N / 2 - 1;
    else if (N % 4 == 1)
    {
        r = N / 2 - 1;
        c = N / 2;
    }
    else
        r = c = N / 2;

    fill(&grid[0][0], &grid[N][N], 'W');
    draw(r, c, N);

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
            cout << grid[r][c];
        cout << '\n';
    }
}