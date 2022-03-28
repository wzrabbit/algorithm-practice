#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

char graph[739][739];
bool visited[739][739];

struct loc
{
    int ro, co;

    bool operator<(const loc &var) const
    {
        if (ro != var.ro)
        {
            return ro < var.ro;
        }
        else
        {
            return co < var.co;
        }
    }
};

struct qData
{
    int ro, co;
    long long int bit;
};

int cnt = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
map<loc, int> getEVInt;
map<int, loc> getEVloc;
map<int, char> getCode;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    int id = 0;
    getCode[0] = 'N';
    getCode[1] = 'N';
    getCode[2] = 'S';
    getCode[3] = 'W';
    getCode[4] = 'E';

    cin >> row >> col;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> graph[r][c];
            if (graph[r][c] == '?')
            {
                getEVInt[{r, c}] = id;
                getEVloc[id] = {r, c};
                id++;
            }
        }
    }

    queue<qData> que;
    qData result = {-1, -1, -1};
    int startR, startC;
    cin >> startR >> startC;
    que.push({startR - 1, startC - 1, 5000000000000000000});
    visited[startR - 1][startC - 1] = true;

    while (que.size())
    {
        int r_ = que.front().ro;
        int c_ = que.front().co;
        long long int b_ = que.front().bit;
        que.pop();

        if (graph[r_][c_] == 'P' || graph[r_][c_] == 'B')
        {
            result = {r_, c_, b_};
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = r_ + dr[i];
            int c = c_ + dc[i];

            if (graph[r][c] == '?')
            {
                r += dr[i];
                c += dc[i];
                if (r >= 0 && r < row && c >= 0 && c < col && visited[r][c] == false && graph[r][c] != '#' && ((graph[r_][c_] == '1' && graph[r][c] != '1') || (graph[r_][c_] != '1' && graph[r][c] == '1')))
                {
                    int evNo = getEVInt[{r - dr[i], c - dc[i]}];
                    long long int evVisited = b_ / (long long int)pow(10, evNo) % 10;
                    if (evVisited == 0)
                    {
                        int dir;
                        switch (i)
                        {
                        case 0:
                            if (graph[r_][c_] == '1' && graph[r][c] != '1')
                                dir = 2;
                            else
                                dir = 1;
                            break;
                        case 1:
                            if (graph[r_][c_] == '1' && graph[r][c] != '1')
                                dir = 1;
                            else
                                dir = 2;
                            break;
                        case 2:
                            if (graph[r_][c_] == '1' && graph[r][c] != '1')
                                dir = 4;
                            else
                                dir = 3;
                            break;
                        case 3:
                            if (graph[r_][c_] == '1' && graph[r][c] != '1')
                                dir = 3;
                            else
                                dir = 4;
                            break;
                        }
                        long long int b = b_ + (long long int)(dir) * (long long int)pow(10, evNo);
                        visited[r][c] = true;
                        que.push({r, c, b});
                    }
                }
            }
            else
            {
                if (r >= 0 && r < row && c >= 0 && c < col && visited[r][c] == false && graph[r][c] != '#' && ((graph[r_][c_] == '1' && graph[r][c] == '1') || (graph[r_][c_] != '1' && graph[r][c] != '1')))
                {
                    visited[r][c] = true;
                    que.push({r, c, b_});
                }
            }
        }
    }

    if (result.ro == -1)
    {
        cout << -1;
    }
    else
    {
        long long int num = result.bit;
        for (int i = 0; i < id; i++)
        {
            int cr = num % 10;
            graph[getEVloc[i].ro][getEVloc[i].co] = getCode[cr];
            num /= 10;
        }

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cout << graph[r][c];
            }
            cout << '\n';
        }
    }
}