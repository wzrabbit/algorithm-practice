#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e8 + 1
using namespace std;

int dist[102][102];
int history[102][102];
vector<int> path;

void get_path(int start, int end)
{
    if (history[start][end] != 0)
    {
        get_path(start, history[start][end]);
        path.push_back(history[start][end]);
        get_path(history[start][end], end);
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int vertex, edge, s, e, d;
    cin >> vertex >> edge;

    fill(&dist[1][1], &dist[vertex][vertex + 1], INF);

    for (int i = 0; i < edge; i++)
    {
        cin >> s >> e >> d;

        if (d < dist[s][e])
            dist[s][e] = d;
    }

    for (int i = 1; i <= vertex; i++)
        dist[i][i] = 0;

    for (int m = 1; m <= vertex; m++)
    {
        for (int s = 1; s <= vertex; s++)
        {
            for (int e = 1; e <= vertex; e++)
            {
                if (dist[s][m] + dist[m][e] < dist[s][e])
                {
                    dist[s][e] = dist[s][m] + dist[m][e];
                    history[s][e] = m;
                }
            }
        }
    }

    for (int r = 1; r <= vertex; r++)
    {
        for (int c = 1; c <= vertex; c++)
        {
            if (dist[r][c] == INF || dist[r][c] == 0)
            {
                cout << 0 << ' ';
                dist[r][c] = INF;
            }
            else
                cout << dist[r][c] << ' ';
        }
        cout << '\n';
    }

    for (int r = 1; r <= vertex; r++)
    {
        for (int c = 1; c <= vertex; c++)
        {
            if (dist[r][c] == INF)
                cout << 0 << '\n';
            else
            {
                path.clear();

                path.push_back(r);
                get_path(r, c);
                path.push_back(c);

                cout << path.size() << ' ';
                for (int i = 0; i < path.size(); i++)
                    cout << path[i] << ' ';
                cout << '\n';
            }
        }
    }
}