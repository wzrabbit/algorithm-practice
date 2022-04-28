#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100
using namespace std;

int graph[51][52];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(&graph[0][0], &graph[50][51], INF);

    int n;
    cin >> n;
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    for (int m = 1; m <= n; m++)
    {
        for (int s = 1; s <= n; s++)
        {
            for (int e = 1; e <= n; e++)
            {
                if (graph[s][m] + graph[m][e] < graph[s][e])
                    graph[s][e] = graph[s][m] + graph[m][e];
            }
        }
    }

    int min_ = INF;
    vector<int> master;
    for (int r = 1; r <= n; r++)
    {
        int current = 0;
        for (int c = 1; c <= n; c++)
        {
            if (graph[r][c] > current)
                current = graph[r][c];
        }

        if (current < min_)
        {
            master.clear();
            min_ = current;
        }

        if (current <= min_)
            master.push_back(r);
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cout << graph[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << min_ << ' ' << master.size() << '\n';
    for (int i = 0; i < master.size(); i++)
        cout << master[i] << ' ';
}
