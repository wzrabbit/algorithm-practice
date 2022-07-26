#include <iostream>
#include <algorithm>
#include <queue>
#define INF 1000000
using namespace std;

struct Loc
{
    int r, c, t;
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

char board[700][700];
bool vis[700][700];
bool pirate_vis[700][700];
int pirate_r[700][700];
int pirate_c[700][700];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;
    Loc pirate_start;
    Loc suah_start;

    fill(&pirate_r[0][0], &pirate_r[R - 1][C], INF);
    fill(&pirate_c[0][0], &pirate_c[R - 1][C], INF);

    for (int r = 0; r < R; r++)
        cin >> board[r];

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (board[r][c] == 'Y')
            {
                suah_start.r = r;
                suah_start.c = c;
                suah_start.t = 0;
            }

            if (board[r][c] == 'V')
            {
                pirate_start.r = r;
                pirate_start.c = c;
                pirate_start.t = 0;
            }
        }
    }

    // 해적 BFS
    queue<Loc> q;
    q.push(pirate_start);
    pirate_vis[pirate_start.r][pirate_start.c] = true;

    while (q.size())
    {
        Loc cur = q.front();
        q.pop();

        if (pirate_r[cur.r][cur.c] == INF)
        {
            int r = cur.r;
            while (r >= 0 && pirate_r[r][cur.c] == INF && board[r][cur.c] != 'I')
            {
                pirate_r[r][cur.c] = cur.t;
                r--;
            }

            r = cur.r + 1;
            while (r < R && pirate_r[r][cur.c] == INF && board[r][cur.c] != 'I')
            {
                pirate_r[r][cur.c] = cur.t;
                r++;
            }
        }

        if (pirate_c[cur.r][cur.c] == INF)
        {
            int c = cur.c;
            while (c >= 0 && pirate_c[cur.r][c] == INF && board[cur.r][c] != 'I')
            {
                pirate_c[cur.r][c] = cur.t;
                c--;
            }

            c = cur.c + 1;
            while (c < C && pirate_c[cur.r][c] == INF && board[cur.r][c] != 'I')
            {
                pirate_c[cur.r][c] = cur.t;
                c++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < R && c >= 0 && c < C &&
                board[r][c] != 'I' && !pirate_vis[r][c])
            {
                pirate_vis[r][c] = true;
                q.push({r, c, cur.t + 1});
            }
        }
    }

    // 수아 BFS
    bool success = false;
    q.push(suah_start);
    vis[suah_start.r][suah_start.c] = true;

    while (q.size())
    {
        Loc cur = q.front();
        q.pop();

        if (board[cur.r][cur.c] == 'T')
        {
            success = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < R && c >= 0 && c < C && board[r][c] != 'I' &&
                !vis[r][c] && cur.t + 1 < min(pirate_r[r][c], pirate_c[r][c]))
            {
                vis[r][c] = true;
                q.push({r, c, cur.t + 1});
            }
        }
    }

    if (success)
        cout << "YES";
    else
        cout << "NO";
}