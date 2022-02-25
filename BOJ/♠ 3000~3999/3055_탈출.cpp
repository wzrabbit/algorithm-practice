#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char graph[51][51];
int water[51][51];
int gosm[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct loc
{
    int ro, co;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    queue<loc> waterQue;
    queue<loc> gosmQue;
    bool success = false;
    fill(&water[0][0], &water[49][50], -1);
    fill(&gosm[0][0], &gosm[49][50], -1);
    cin >> row >> col;
    for (int r = 0; r < row; r++)
    {
        cin >> &graph[r][0];
    }
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (graph[r][c] == '*')
            {
                waterQue.push({r, c});
                water[r][c] = 0;
            }
            else if (graph[r][c] == 'S')
            {
                gosmQue.push({r, c});
                gosm[r][c] = 0;
            }
        }
    }

    while (waterQue.size())
    {
        int r_ = waterQue.front().ro;
        int c_ = waterQue.front().co;
        waterQue.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = r_ + dr[i];
            int c = c_ + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col && water[r][c] == -1 && graph[r][c] != 'X' && graph[r][c] != 'D')
            {
                water[r][c] = water[r_][c_] + 1;
                waterQue.push({r, c});
            }
        }
    }

    while (gosmQue.size())
    {
        int r_ = gosmQue.front().ro;
        int c_ = gosmQue.front().co;
        gosmQue.pop();

        if (graph[r_][c_] == 'D')
        {
            success = true;
            cout << gosm[r_][c_];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = r_ + dr[i];
            int c = c_ + dc[i];

            if (r >= 0 && r < row && c >= 0 && c < col && gosm[r][c] == -1 && graph[r][c] != 'X' && (water[r][c] > gosm[r_][c_] + 1 || water[r][c] == -1))
            {
                gosm[r][c] = gosm[r_][c_] + 1;
                gosmQue.push({r, c});
            }
        }
    }

    if (success == false)
        cout << "KAKTUS";
}