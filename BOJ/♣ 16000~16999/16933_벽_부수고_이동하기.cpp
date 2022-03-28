#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited[11][1000][1000] = {};
int graph[1000][1000] = {};
queue<pair<pair<int, int>, pair<int, int>>> que;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col, bomb;
    cin >> row >> col >> bomb;
    char d;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> d;
            graph[r][c] = d;
        }
    }

    que.push(make_pair(make_pair(0, 0), make_pair(1, bomb)));
    int success = false;
    while (que.size())
    {
        int r = que.front().first.first;
        int c = que.front().first.second;
        int d = que.front().second.first;
        int b = que.front().second.second;
        int re = false;
        que.pop();

        if (r == row - 1 && c == col - 1)
        {
            success = true;
            cout << d << '\n';
            break;
        }

        for (int i = 0; i <= 3; i++)
        {
            int r_ = r + dr[i];
            int c_ = c + dc[i];
            if (r_ >= 0 && r_ < row && c_ >= 0 && c < col && visited[b][r_][c_] == false)
            {
                if (graph[r_][c_] == '0')
                {
                    visited[b][r_][c_] = true;
                    que.push(make_pair(make_pair(r_, c_), make_pair(d + 1, b)));
                }
                else if (b != 0)
                {
                    if (d % 2 == 0)
                    {
                        if (re == false)
                        {
                            re = true;
                            que.push(make_pair(make_pair(r, c), make_pair(d + 1, b)));
                        }
                    }
                    else
                    {
                        visited[b][r_][c_] = true;
                        que.push(make_pair(make_pair(r_, c_), make_pair(d + 1, b - 1)));
                    }
                }
            }
        }
    }

    if (!success)
        cout << "-1\n";
}