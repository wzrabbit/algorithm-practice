#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[101][3][10][10] = {};
int graph[10][10] = {};
int kr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int kc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int rr[4] = {-1, 1, 0, 0};
int rc[4] = {0, 0, -1, 1};
int br[4] = {-1, -1, 1, 1};
int bc[4] = {-1, 1, -1, 1};

struct qData
{
    int row, col, mode, dist, level;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, data;
    queue<qData> que;
    cin >> width;
    int goal = width * width;

    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            cin >> data;
            graph[r][c] = data;
            if (data == 1)
            {
                que.push({r, c, 0, 0, 1});
                que.push({r, c, 1, 0, 1});
                que.push({r, c, 2, 0, 1});
                visited[1][0][r][c] = 1;
                visited[1][1][r][c] = 1;
                visited[1][2][r][c] = 1;
            }
        }
    }

    while (que.size())
    {
        qData q = que.front();
        que.pop();
        int r_ = q.row;
        int c_ = q.col;
        int m = q.mode;
        int d = q.dist;
        int l = q.level;

        if (l == goal)
        {
            cout << d;
            break;
        }

        if (m == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int r = r_ + kr[i];
                int c = c_ + kc[i];

                if (r >= 0 && r < width && c >= 0 && c < width)
                {
                    if (graph[r][c] == l + 1)
                    {
                        if (visited[l + 1][0][r][c] == 0)
                        {
                            visited[l + 1][0][r][c] = 1;
                            que.push({r, c, 0, d + 1, l + 1});
                        }
                    }
                    else
                    {
                        if (visited[l][0][r][c] == 0)
                        {
                            visited[l][0][r][c] = 1;
                            que.push({r, c, 0, d + 1, l});
                        }
                    }
                }
            }
        }

        else if (m == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int r = r_ + rr[i];
                int c = c_ + rc[i];
                while (r >= 0 && r < width && c >= 0 && c < width)
                {
                    if (graph[r][c] == l + 1)
                    {
                        if (visited[l + 1][1][r][c] == 0)
                        {
                            visited[l + 1][1][r][c] = 1;
                            que.push({r, c, 1, d + 1, l + 1});
                        }
                    }
                    else
                    {
                        if (visited[l][1][r][c] == 0)
                        {
                            visited[l][1][r][c] = 1;
                            que.push({r, c, 1, d + 1, l});
                        }
                    }

                    r += rr[i];
                    c += rc[i];
                }
            }
        }

        else
        {
            for (int i = 0; i < 4; i++)
            {
                int r = r_ + br[i];
                int c = c_ + bc[i];
                while (r >= 0 && r < width && c >= 0 && c < width)
                {
                    if (graph[r][c] == l + 1)
                    {
                        if (visited[l + 1][2][r][c] == 0)
                        {
                            visited[l + 1][2][r][c] = 1;
                            que.push({r, c, 2, d + 1, l + 1});
                        }
                    }
                    else
                    {
                        if (visited[l][2][r][c] == 0)
                        {
                            visited[l][2][r][c] = 1;
                            que.push({r, c, 2, d + 1, l});
                        }
                    }

                    r += br[i];
                    c += bc[i];
                }
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (m != i && visited[l][i][r_][c_] == 0)
            {
                visited[l][i][r_][c_] = 1;
                que.push({r_, c_, i, d + 1, l});
            }
        }
    }
}