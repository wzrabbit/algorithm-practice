#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

char graph[501][501];
bool visited[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
struct loc
{
    int ro, co, dist;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col, range;
    cin >> row >> col >> range;

    for (int r = 0; r < row; r++)
    {
        cin >> &graph[r][0];
    }

    deque<loc> que;
    bool vFind = false;
    que.push_back({0, 0, 0});

    while (que.size())
    {
        int r_ = que.front().ro;
        int c_ = que.front().co;
        int d = que.front().dist;
        que.pop_front();

        if (visited[r_][c_])
            continue;
        visited[r_][c_] = true;

        if (r_ == row - 1 && c_ == col - 1)
        {
            cout << d;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = r_ + dr[i];
            int c = c_ + dc[i];
            int blocked = false;

            if (r >= 0 && r < row && c >= 0 && c < col && !visited[r][c])
            {
                if (graph[r][c] == '.')
                {
                    que.push_front({r, c, d});
                }
                else
                {
                    blocked = true;
                }
            }

            r = r_ + dr[i] * range;
            c = c_ + dc[i] * range;

            if (blocked)
            {
                if (i == 0 || i == 1)
                {
                    for (int j = c - range + 1; j <= c + range - 1; j++)
                    {
                        if (r >= 0 && r < row && j >= 0 && j < col && !visited[r][j])
                        {
                            que.push_back({r, j, d + 1});
                        }
                        else if (r >= row - 1 && j >= col - 1 && !vFind)
                        {
                            vFind = true;
                            que.push_back({row - 1, col - 1, d + 1});
                        }
                    }
                }
                else
                {
                    for (int j = r - range + 1; j <= r + range - 1; j++)
                    {
                        if (j >= 0 && j < row && c >= 0 && c < col && !visited[j][c])
                        {
                            que.push_back({j, c, d + 1});
                        }
                        else if (j >= row - 1 && c >= col - 1 && !vFind)
                        {
                            vFind = true;
                            que.push_back({row - 1, col - 1, d + 1});
                        }
                    }
                }
            }
        }
    }
}