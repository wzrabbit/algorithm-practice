#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char graph[101][101];
int visited[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char df[5] = {'D', 'U', 'R', 'L'};
struct loc
{
    int ro, co;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int limit, row, col;
    bool success = false;
    queue<loc> que;
    cin >> limit >> row >> col;

    fill(&visited[0][0], &visited[100][100], -1);

    for (int r = 0; r < row; r++)
    {
        cin >> graph[r];
        for (int c = 0; c < col; c++)
        {
            if (graph[r][c] == 'S')
            {
                que.push({r, c});
                visited[r][c] = 0;
            }
        }
    }

    while (que.size())
    {
        loc current = que.front();
        que.pop();

        if (current.ro == 0 || current.co == 0 || current.ro == row - 1 || current.co == col - 1)
        {
            success = true;
            cout << visited[current.ro][current.co];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = current.ro + dr[i];
            int c = current.co + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col &&
                visited[r][c] == -1 && graph[r][c] != '1' && visited[current.ro][current.co] < limit)
            {
                if (graph[r][c] == '0' || graph[r][c] == df[i])
                {
                    visited[r][c] = visited[current.ro][current.co] + 1;
                    que.push({r, c});
                }
            }
        }
    }

    if (!success)
        cout << "NOT POSSIBLE";
}