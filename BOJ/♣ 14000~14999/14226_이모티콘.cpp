#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visited[1001][2001];
struct qData
{
    int clip, emoji, time;
};
queue<qData> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&visited[0][0], &visited[1000][2000], -1);
    visited[0][0] = 0;

    int num;
    cin >> num;
    que.push({0, 1, 0});

    while (que.size())
    {
        int c = que.front().clip;
        int e = que.front().emoji;
        int t = que.front().time;
        que.pop();

        if (e == num)
        {
            cout << t;
            break;
        }

        if (e < num && visited[e][e] == -1)
        {
            visited[e][e] = t + 1;
            que.push({e, e, t + 1});
        }
        if (e < num && visited[c][e + c] == -1)
        {
            visited[c][e + c] = t + 1;
            que.push({c, e + c, t + 1});
        }
        if (e > 0 && visited[c][e - 1] == -1)
        {
            visited[c][e - 1] = t + 1;
            que.push({c, e - 1, t + 1});
        }
    }
}