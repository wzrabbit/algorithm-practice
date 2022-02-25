#include <iostream>
#include <algorithm>
using namespace std;

int visited[100002];
int selected[100001];
int cnt = 0;

int traverse(int c)
{
    if (visited[c] == 1)
        return c;
    else if (visited[c] == 2)
        return 0;

    visited[c] = 1;
    int s = traverse(selected[c]);
    if (s == 0)
    {
        cnt++;
        visited[c] = 2;
        return 0;
    }
    else if (s == c)
    {
        visited[c] = 2;
        return 0;
    }
    else
    {
        visited[c] = 2;
        return s;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, n;

    cin >> tc;
    while (tc--)
    {
        cin >> n;
        fill(&visited[1], &visited[n + 1], 0);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> selected[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
                traverse(i);
        }

        cout << cnt << '\n';
    }
}