#include <iostream>
#include <algorithm>
#include <queue>
#define INF 10000
using namespace std;

// board[몇번째 판][회전][행][열]
int board[5][4][5][5];
int game[5][5][5];
int visited[5][5][5];
int board_cases[120][5];
int dr[6] = {-1, 1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dl[6] = {0, 0, 0, 0, -1, 1};

struct loc
{
    int level, row, col;
};

int play_game(int b[5], int s[5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
                game[i][r][c] = board[b[i]][s[i]][r][c];
        }
    }
    fill(&visited[0][0][0], &visited[4][4][5], -1);

    queue<loc> que;
    if (game[0][0][0] == 1)
    {
        visited[0][0][0] = 0;
        que.push({0, 0, 0});
    }

    while (que.size())
    {
        loc p = que.front();
        que.pop();

        if (p.level == 4 && p.row == 4 && p.col == 4)
            return visited[4][4][4];

        for (int i = 0; i < 6; i++)
        {
            int l = p.level + dl[i];

            int r = p.row + dr[i];
            int c = p.col + dc[i];

            if (l >= 0 && l < 5 && r >= 0 && r < 5 && c >= 0 && c < 5 &&
                visited[l][r][c] == -1 && game[l][r][c] == 1)
            {
                visited[l][r][c] = visited[p.level][p.row][p.col] + 1;
                que.push({l, r, c});
            }
        }
    }

    return INF;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int n = 0; n < 5; n++)
    {
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
                cin >> board[n][0][r][c];
        }

        for (int s = 1; s < 4; s++)
        {
            for (int r = 0; r < 5; r++)
            {
                for (int c = 0; c < 5; c++)
                    board[n][s][c][4 - r] = board[n][s - 1][r][c];
            }
        }
    }

    int count = 0;
    for (int b1 = 0; b1 < 5; b1++)
    {
        for (int b2 = 0; b2 < 5; b2++)
        {
            for (int b3 = 0; b3 < 5; b3++)
            {
                for (int b4 = 0; b4 < 5; b4++)
                {
                    for (int b5 = 0; b5 < 5; b5++)
                    {
                        if (b1 == b2 || b1 == b3 || b1 == b4 || b1 == b5 ||
                            b2 == b3 || b2 == b4 || b2 == b5 || b3 == b4 ||
                            b3 == b5 || b4 == b5)
                            continue;
                        board_cases[count][0] = b1;
                        board_cases[count][1] = b2;
                        board_cases[count][2] = b3;
                        board_cases[count][3] = b4;
                        board_cases[count][4] = b5;
                        count++;
                    }
                }
            }
        }
    }

    int _min = INF;
    for (int s1 = 0; s1 < 4; s1++)
    {
        for (int s2 = 0; s2 < 4; s2++)
        {
            for (int s3 = 0; s3 < 4; s3++)
            {
                for (int s4 = 0; s4 < 4; s4++)
                {
                    for (int s5 = 0; s5 < 4; s5++)
                    {
                        for (int i = 0; i < 120; i++)
                        {
                            int b1 = board_cases[i][0];
                            int b2 = board_cases[i][1];
                            int b3 = board_cases[i][2];
                            int b4 = board_cases[i][3];
                            int b5 = board_cases[i][4];

                            int b[5] = {b1, b2, b3, b4, b5};
                            int s[5] = {s1, s2, s3, s4, s5};

                            int result = play_game(b, s);
                            _min = min(result, _min);
                        }
                    }
                }
            }
        }
    }

    if (_min == INF)
        cout << -1;
    else
        cout << _min;
}