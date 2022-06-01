#include <iostream>
#include <queue>
using namespace std;

struct q_data
{
    int mr, mc, cr, cc, dist;
};
struct m_data
{
    int r, c;
};
int board[7][7];
bool visited[4][7][7];
bool m_visited[7][7];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int col, row;

bool man_move(int mr, int mc, int cr, int cc, int obr, int obc)
{
    fill(&m_visited[0][0], &m_visited[6][7], false);
    queue<m_data> m_que;
    m_visited[mr][mc] = true;
    m_que.push({mr, mc});

    while (m_que.size())
    {
        m_data p = m_que.front();
        m_que.pop();

        if (p.r == cr && p.c == cc)
            return true;

        for (int i = 0; i < 4; i++)
        {
            int r = p.r + dr[i];
            int c = p.c + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col &&
                m_visited[r][c] == false && board[r][c] != 1 && (r != obr || c != obc))
            {
                m_visited[r][c] = true;
                m_que.push({r, c});
            }
        }
    }

    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int ms_row, ms_col, cs_row, cs_col;
        bool success = false;
        cin >> col >> row;

        if (row == 0 && col == 0)
            break;

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cin >> board[r][c];

                if (board[r][c] == 2)
                {
                    cs_row = r;
                    cs_col = c;
                }
                else if (board[r][c] == 4)
                {
                    ms_row = r;
                    ms_col = c;
                }
            }
        }

        fill(&visited[0][0][0], &visited[3][6][7], false);
        queue<q_data> que;
        que.push({ms_row, ms_col, cs_row, cs_col, 0});
        while (que.size())
        {
            q_data p = que.front();
            que.pop();

            if (board[p.cr][p.cc] == 3)
            {
                success = true;
                cout << p.dist << '\n';
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int cr = p.cr + dr[i];
                int cc = p.cc + dc[i];
                int cr2 = p.cr - dr[i];
                int cc2 = p.cc - dc[i];

                if (cr >= 0 && cr < row && cc >= 0 && cc < col &&
                    cr2 >= 0 && cr2 < row && cc2 >= 0 && cc2 < col && board[cr][cc] != 1 &&
                    visited[i][cr][cc] == false && man_move(p.mr, p.mc, cr2, cc2, p.cr, p.cc))
                {
                    visited[i][cr][cc] = true;
                    que.push({p.cr, p.cc, cr, cc, p.dist + 1});
                }
            }
        }

        if (!success)
            cout << -1 << '\n';
    }
}