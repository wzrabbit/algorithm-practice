#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int visited[501][502];
int R, C, UR, UC, B;
int start_R, start_C, end_R, end_C;

struct q_data
{
    int r, c;
};

bool is_blocked(int start_R, int start_C, int end_R, int end_C)
{
    for (int r = start_R; r <= end_R; r++)
    {
        for (int c = start_C; c <= end_C; c++)
        {
            if (visited[r][c] == -2)
                return true;
        }
    }

    return false;
}

int bfs()
{
    queue<q_data> q;
    q.push({start_R, start_C});
    visited[start_R][start_C] = 0;

    while (q.size())
    {
        q_data cur = q.front();
        q.pop();

        if (cur.r == end_R && cur.c == end_C)
            return visited[cur.r][cur.c];

        if (cur.r - 1 >= 1 && visited[cur.r - 1][cur.c] == -1 &&
            !is_blocked(cur.r - 1, cur.c, cur.r - 1, cur.c + UC - 1))
        {
            visited[cur.r - 1][cur.c] = visited[cur.r][cur.c] + 1;
            q.push({cur.r - 1, cur.c});
        }

        if (cur.r + 1 <= R - UR + 1 && visited[cur.r + 1][cur.c] == -1 &&
            !is_blocked(cur.r + UR, cur.c, cur.r + UR, cur.c + UC - 1))
        {
            visited[cur.r + 1][cur.c] = visited[cur.r][cur.c] + 1;
            q.push({cur.r + 1, cur.c});
        }

        if (cur.c - 1 >= 1 && visited[cur.r][cur.c - 1] == -1 &&
            !is_blocked(cur.r, cur.c - 1, cur.r + UR - 1, cur.c - 1))
        {
            visited[cur.r][cur.c - 1] = visited[cur.r][cur.c] + 1;
            q.push({cur.r, cur.c - 1});
        }

        if (cur.c + 1 <= C - UC + 1 && visited[cur.r][cur.c + 1] == -1 &&
            !is_blocked(cur.r, cur.c + UC, cur.r + UR - 1, cur.c + UC))
        {
            visited[cur.r][cur.c + 1] = visited[cur.r][cur.c] + 1;
            q.push({cur.r, cur.c + 1});
        }
    }

    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> UR >> UC >> B;
    fill(&visited[1][1], &visited[R][C + 1], -1);

    for (int i = 0; i < B; i++)
    {
        int r, c;
        cin >> r >> c;
        visited[r][c] = -2;
    }

    cin >> start_R >> start_C >> end_R >> end_C;
    if (is_blocked(start_R, start_C, start_R + UR - 1, start_C + UC - 1))
        cout << -1;
    else
        cout << bfs();
}