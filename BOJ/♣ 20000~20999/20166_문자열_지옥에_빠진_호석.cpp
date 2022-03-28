#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

char graph[11][11];
int row, col, like, cases;
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1};
unordered_map<string, int> dict;
string l;

void traverse(int r, int c, int cnt)
{
    if (cnt == l.length())
    {
        cases++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int r_ = dr[i] + r;
        int c_ = dc[i] + c;

        if (r_ == row)
            r_ = 0;
        else if (r_ == -1)
            r_ = row - 1;
        if (c_ == col)
            c_ = 0;
        else if (c_ == -1)
            c_ = col - 1;

        if (graph[r_][c_] == l[cnt])
        {
            traverse(r_, c_, cnt + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col >> like;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> graph[r][c];
        }
    }

    while (like--)
    {
        cases = 0;
        cin >> l;

        if (dict.find(l) != dict.end())
        {
            cout << dict[l] << '\n';
            continue;
        }

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (graph[r][c] == l[0])
                {
                    traverse(r, c, 1);
                }
            }
        }

        dict[l] = cases;
        cout << cases << '\n';
    }
}