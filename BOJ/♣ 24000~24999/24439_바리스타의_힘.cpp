#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct loc
{
    int ro, co, lv, ignore;
};

int maze[1001][1001];
int visited[4][1001][1002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int solve(int row, int col)
{
    queue<loc> que;
    que.push({1, 1, 0, -1});
    visited[0][1][1] = 0;

    while (que.size())
    {
        loc node = que.front();
        que.pop();

        if (node.ro == row && node.co == col)
            return visited[node.lv][node.ro][node.co];

        for (int i = 0; i < 4; i++)
        {
            int r = node.ro + dr[i];
            int c = node.co + dc[i];
            int l = node.lv;
            int g = node.ignore;

            if (r >= 1 && r <= row && c >= 1 && c <= col)
            {
                if (l == 0 || l == 3)
                {
                    if (visited[l][r][c] == -1 && maze[r][c] == 0)
                    {
                        visited[l][r][c] = visited[node.lv][node.ro][node.co] + 1;
                        que.push({r, c, l, -1});
                    }
                }

                if (l == 0)
                {
                    int next_lv = 1;
                    if (i >= 2)
                        next_lv = 2;

                    if (visited[next_lv][r][c] == -1)
                    {
                        visited[next_lv][r][c] = visited[node.lv][node.ro][node.co] + 1;
                        que.push({r, c, next_lv, (next_lv - 1) * 2});
                        que.push({r, c, next_lv, (next_lv - 1) * 2 + 1});
                    }
                }

                if (l == 1 || l == 2)
                {
                    if (i == g)
                    {
                        if (visited[l][r][c] == -1)
                        {
                            visited[l][r][c] = visited[node.lv][node.ro][node.co] + 1;
                            que.push({r, c, l, g});
                        }
                    }

                    if (visited[3][r][c] == -1 && maze[r][c] == 0)
                    {
                        visited[3][r][c] = visited[node.lv][node.ro][node.co] + 1;
                        que.push({r, c, 3, -1});
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
            scanf("%1d", &maze[r][c]);
    }

    fill(&visited[0][1][1], &visited[3][1000][1001], -1);
    printf("%d", solve(row, col));
}