#include <iostream>
#include <algorithm>
#include <queue>
#define INF 10000000
using namespace std;

struct Loc
{
    int r, c, t, d;
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

char board[1001][1001];
int visited[2][1000][1000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int R, C, P;
    Loc start_loc;
    Loc end_loc;
    int answer = -1;

    cin >> R >> C >> P;

    fill(&visited[0][0][0], &visited[1][R - 1][C], INF);

    for (int r = 0; r < R; r++)
        cin >> board[r];

    cin >> start_loc.r >> start_loc.c;
    cin >> end_loc.r >> end_loc.c;
    start_loc.r--;
    start_loc.c--;
    end_loc.r--;
    end_loc.c--;

    queue<Loc> q;
    q.push({start_loc.r, start_loc.c, 0, 0});
    q.push({start_loc.r, start_loc.c, 1, 0});
    visited[0][start_loc.r][start_loc.c] = 0;
    visited[1][start_loc.r][start_loc.c] = 0;

    while (q.size())
    {
        Loc cur = q.front();
        q.pop();

        if (cur.r == end_loc.r && cur.c == end_loc.c)
        {
            answer = cur.d;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = cur.r;
            int c = cur.c;

            for (int j = 0; j < P; j++)
            {
                r += dr[i];
                c += dc[i];

                if (r >= 0 && r < R && c >= 0 && c < C &&
                    board[r][c] == '.' && visited[i / 2][r][c] >= cur.d + 1)
                {
                    if (visited[0][r][c] >= cur.d + 1)
                    {
                        visited[0][r][c] = cur.d + 1;
                        q.push({r, c, 0, cur.d + 1});
                    }

                    if (visited[0][r][c] >= cur.d + 1)
                    {
                        visited[1][r][c] = cur.d + 1;
                        q.push({r, c, 1, cur.d + 1});
                    }
                }
                else
                    break;
            }
        }
    }

    cout << answer;
}