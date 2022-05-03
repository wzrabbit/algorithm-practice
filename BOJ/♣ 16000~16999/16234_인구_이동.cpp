#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

struct loc
{
    int row, col;
};
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int board[51][51];
int visited[51][51];
int next_val[2501];
int n, lo, hi;
int day = 0;

void traverse(int start_row, int start_col, int no)
{
    queue<loc> que;
    double sum = 0;
    double group = 0;
    que.push({start_row, start_col});
    visited[start_row][start_col] = no;

    while (que.size())
    {
        int r_ = que.front().row;
        int c_ = que.front().col;
        sum += board[r_][c_];
        group++;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = r_ + dr[i];
            int c = c_ + dc[i];

            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == -1)
            {
                int gap = abs(board[r_][c_] - board[r][c]);
                if (gap < lo || gap > hi)
                    continue;

                visited[r][c] = no;
                que.push({r, c});
            }
        }
    }

    next_val[no] = trunc(sum / group);
}

void paint()
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (visited[r][c] != -1)
                board[r][c] = next_val[visited[r][c]];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> lo >> hi;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
            cin >> board[r][c];
    }

    while (true)
    {
        fill(&visited[0][0], &visited[n][n], -1);

        int group_cnt = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (visited[r][c] == -1)
                {
                    traverse(r, c, group_cnt);
                    group_cnt++;
                }
            }
        }

        if (group_cnt == n * n)
            break;
        day++;

        paint();
    }

    cout << day;
}