#include <iostream>
#include <queue>
using namespace std;

short board[10002];
bool visited[10002] = {};
short dr[2] = {-1, 1};
struct qData
{
    short loc, dist;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short n, start, end;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> board[i];
    }
    cin >> start >> end;

    queue<qData> que;
    que.push({start, 0});
    visited[start] = true;
    bool success = false;

    while (que.size())
    {
        qData current = que.front();
        que.pop();

        if (current.loc == end)
        {
            success = true;
            cout << current.dist;
            break;
        }

        for (int i = 0; i < 2; i++)
        {
            short m = current.loc + dr[i] * board[current.loc];
            while (m >= 1 && m <= n)
            {
                if (!visited[m])
                {
                    visited[m] = true;
                    que.push({m, current.dist + 1});
                }
                m += dr[i] * board[current.loc];
            }
        }
    }

    if (!success)
        cout << -1;
}