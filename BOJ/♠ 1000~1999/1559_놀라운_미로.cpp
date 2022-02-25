#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

bool visited[256][100][100] = {};
char graph[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
map<char, int> canPass;

void clearData()
{
    for (int a = 0; a < 256; a++)
    {
        for (int b = 0; b < 100; b++)
        {
            for (int c = 0; c < 100; c++)
            {
                visited[a][b][c] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    canPass['N'] = 0;
    canPass['E'] = 1;
    canPass['S'] = 2;
    canPass['W'] = 3;

    while (true)
    {
        int row, col;
        char input;
        cin >> row >> col;
        if (row == 0)
            break;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                cin >> input;
                graph[r][c] = input;
            }
        }

        int key;
        int a, b;
        int id = 0;
        map<int, int> isKey;
        cin >> key;
        for (int k = 0; k < key; k++)
        {
            cin >> a >> b;
            a--;
            b--;
            isKey[a * col + b] = id++;
        }
        int goal = (int)pow(2, id) - 1;

        queue<pair<pair<int, int>, pair<int, int>>> que;
        clearData();
        que.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
        visited[0][0][0] = true;
        while (que.size())
        {
            int r = que.front().first.first;
            int c = que.front().first.second;
            int d = que.front().second.first;
            int k = que.front().second.second;
            int re = false;
            que.pop();

            if (r == row - 1 && c == col - 1 && k == goal)
            {
                cout << d << '\n';
                break;
            }

            for (int i = 0; i <= 3; i++)
            {
                int r_ = r + dr[i];
                int c_ = c + dc[i];
                int k_ = k;

                if (isKey.count(r_ * col + c_) != 0)
                {
                    k_ |= 1 << isKey[r_ * col + c_];
                }
                if (r_ >= 0 && r_ < row && c_ >= 0 && c_ < col && visited[k_][r_][c_] == false)
                {
                    if ((d + canPass[graph[r][c]]) % 4 == i)
                    {
                        visited[k_][r_][c_] = true;
                        que.push(make_pair(make_pair(r_, c_), make_pair(d + 1, k_)));
                    }
                    else if (!re)
                    {
                        re = true;
                        que.push(make_pair(make_pair(r, c), make_pair(d + 1, k)));
                    }
                }
            }
        }
    }
}