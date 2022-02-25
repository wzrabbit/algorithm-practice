#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct loc
{
    int row, col;
};
int graph[102][102];
bool visited[102][102];
int minElement = 0;
int maxElement = 200;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool traverse(int limit, int width)
{
    for (int minNum = 0; minNum <= 200 - limit; minNum++)
    {
        int maxNum = minNum + limit;
        if (graph[0][0] < minNum || graph[0][0] > maxNum)
            continue;
        fill(&visited[0][0], &visited[width + 1][width + 1], false);
        queue<loc> que;
        visited[0][0] = true;
        que.push({0, 0});

        while (que.size())
        {
            loc current = que.front();
            que.pop();

            if (current.row == width - 1 && current.col == width - 1)
            {
                return true;
            }

            for (int i = 0; i < 4; i++)
            {
                int r = current.row + dr[i];
                int c = current.col + dc[i];

                if (r >= 0 && r < width && c >= 0 && c < width && visited[r][c] == false)
                {
                    if (graph[r][c] < minNum || graph[r][c] > maxNum)
                        continue;
                    visited[r][c] = true;
                    que.push({r, c});
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width;
    cin >> width;
    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < width; c++)
        {
            cin >> graph[r][c];
        }
    }

    int start = 0;
    int end = 200;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (traverse(mid, width))
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << start;
}