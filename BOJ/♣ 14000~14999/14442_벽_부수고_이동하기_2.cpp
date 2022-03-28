#include <iostream>
#include <queue>
using namespace std;

bool visited[11][1001][1001] = {};
char graph[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
struct qData
{
    int row, col, dist, bomb;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col, bomb;
    cin >> row >> col >> bomb;

    for (int r = 0; r < row; r++)
    {
        cin >> graph[r];
    }

    queue<qData> que;
    que.push({0, 0, 1, bomb});
    visited[bomb][0][0] = true;
    bool success = false;

    while (que.size())
    {
        qData current = que.front();
        que.pop();

        if (current.row == row - 1 && current.col == col - 1)
        {
            success = true;
            cout << current.dist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = current.row + dr[i];
            int c = current.col + dc[i];
            int d = current.dist;
            int b = current.bomb;

            if (r >= 0 && r < row && c >= 0 && c < col)
            {
                if (graph[r][c] == '0')
                {
                    if (visited[b][r][c] == false)
                    {
                        visited[b][r][c] = true;
                        que.push({r, c, d + 1, b});
                    }
                }
                else if (b >= 1)
                {
                    if (visited[b - 1][r][c] == false)
                    {
                        visited[b - 1][r][c] = true;
                        que.push({r, c, d + 1, b - 1});
                    }
                }
            }
        }
    }

    if (!success)
        cout << -1;
}