#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <initializer_list>
#define INF 10e7
using namespace std;

struct pq_data
{
    int r, c, d, t;
};

struct compare
{
    bool operator()(pq_data a, pq_data b)
    {
        return a.d > b.d;
    }
};

int maze[100][100];
int dist[3][100][101];
int row, col, start_r, start_c, end_r, end_c;

int dr[3][4] = {
    {-1, 1, 0, 0},
    {-1, 1, -1, 1},
    {0, 0, 0, 0}};

int dc[3][4] = {
    {0, 0, -1, 1},
    {0, 0, 0, 0},
    {-1, 1, -1, 1}};

void dijkstra()
{
    priority_queue<pq_data, vector<pq_data>, compare> pq;
    pq.push({start_r, start_c, 0, 0});
    dist[0][start_r][start_c] = 0;

    while (pq.size())
    {
        pq_data current = pq.top();
        pq.pop();

        if (current.d > dist[current.t][current.r][current.c])
            continue;

        int t = (current.t + 1) % 3;

        for (int i = 0; i < 4; i++)
        {
            int r = current.r + dr[t][i];
            int c = current.c + dc[t][i];

            if (r >= 0 && r < row && c >= 0 && c < col && maze[r][c] != -1)
            {
                int cost = dist[current.t][current.r][current.c] + maze[r][c];
                if (cost < dist[t][r][c])
                {
                    dist[t][r][c] = cost;
                    pq.push({r, c, cost, t});
                }
            }
        }
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    cin >> row >> col;
    cin >> start_r >> start_c >> end_r >> end_c;
    start_r--;
    start_c--;
    end_r--;
    end_c--;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            cin >> maze[r][c];
    }

    fill(&dist[0][0][0], &dist[2][99][100], INF);

    dijkstra();

    int best = min({dist[0][end_r][end_c],
                    dist[1][end_r][end_c],
                    dist[2][end_r][end_c]});

    if (best == INF)
        cout << -1;
    else
        cout << best;
}