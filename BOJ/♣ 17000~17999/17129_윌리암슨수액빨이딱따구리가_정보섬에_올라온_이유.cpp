#include <iostream>
#include <queue>
using namespace std;

struct q_data
{
    int ro, co, dist;
};
char board[3001][3001];
bool visited[3000][3000];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main()
{
    cin.tie()->sync_with_stdio(0);
    int row, col, start_row, start_col;
    cin >> row >> col;

    for (int r = 0; r < row; r++)
    {
        cin >> board[r];
        for (int c = 0; c < col; c++)
        {
            if (board[r][c] == '2')
            {
                start_row = r;
                start_col = c;
            }
        }
    }

    queue<q_data> que;
    que.push({start_row, start_col, 0});
    visited[start_row][start_col] = true;
    bool success = false;

    while (que.size())
    {
        q_data p = que.front();
        que.pop();

        if (board[p.ro][p.co] == '3' || board[p.ro][p.co] == '4' || board[p.ro][p.co] == '5')
        {
            success = true;
            cout << "TAK\n"
                 << p.dist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = p.ro + dr[i];
            int c = p.co + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col && board[r][c] != '1' && visited[r][c] == false)
            {
                visited[r][c] = true;
                que.push({r, c, p.dist + 1});
            }
        }
    }

    if (success == false)
        cout << "NIE";
}