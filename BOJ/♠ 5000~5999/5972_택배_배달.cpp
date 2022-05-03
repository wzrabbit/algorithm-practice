#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 60000000
using namespace std;

struct pq_data
{
    int vertex, dist;
};
struct compare
{
    bool operator()(pq_data a, pq_data b)
    {
        return a.dist > b.dist;
    }
};
vector<vector<pq_data>> graph(50001);
priority_queue<pq_data, vector<pq_data>, compare> pq;
int dist[50002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e, a, b, c;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(dist, dist + 50001, INF);
    pq.push({1, 0});
    dist[0] = 0;
    while (pq.size())
    {
        pq_data current = pq.top();
        pq.pop();
        int v = current.vertex;
        int d = current.dist;
        if (d > dist[v])
            continue;
        for (int i = 0; i < graph[v].size(); i++)
        {
            int next_v = graph[v][i].vertex;
            int next_d = graph[v][i].dist;
            int cost = d + next_d;
            if (cost < dist[next_v])
            {
                dist[next_v] = cost;
                pq.push({next_v, cost});
            }
        }
    }

    cout << dist[v];
}