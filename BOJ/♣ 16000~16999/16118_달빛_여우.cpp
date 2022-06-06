#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1600000001
using namespace std;

struct pq_data
{
    int v, d, s;
};

struct vertex
{
    int v, d;
};

struct compare
{
    bool operator()(const pq_data &a, const pq_data &b) const
    {
        return a.d > b.d;
    }
};

int dist[3][4002];
vector<vector<vertex>> graph;
int ve, ed;

void dijkstra()
{
    priority_queue<pq_data, vector<pq_data>, compare> pq;

    pq.push({1, 0, 0});
    pq.push({1, 0, 1});
    dist[0][1] = 0;
    // 주의: 시작점으로 다시 돌아와서 달리는 경우가 최적일 수 있으므로, 늑대에 대한 방문 처리는 하지 않음

    while (pq.size())
    {
        pq_data curr = pq.top();
        pq.pop();

        if (curr.d > dist[curr.s][curr.v])
            continue;

        int next_s = 0;
        if (curr.s == 1)
            next_s = 2;
        else if (curr.s == 2)
            next_s = 1;

        for (int i = 0; i < graph[curr.v].size(); i++)
        {
            int next_v = graph[curr.v][i].v;
            int next_d = graph[curr.v][i].d;

            if (curr.s == 1)
                next_d /= 2;
            else if (curr.s == 2)
                next_d *= 2;

            int cost = curr.d + next_d;
            if (cost < dist[next_s][next_v])
            {
                pq.push({next_v, cost, next_s});
                dist[next_s][next_v] = cost;
            }
        }
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int s, e, d;
    cin >> ve >> ed;
    graph.resize(ve + 1);

    for (int i = 0; i < ed; i++)
    {
        cin >> s >> e >> d;
        graph[s].push_back({e, d * 2});
        graph[e].push_back({s, d * 2});
    }

    fill(&dist[0][0], &dist[2][4001], INF);

    dijkstra();

    int count = 0;
    for (int i = 2; i <= ve; i++)
    {
        if (dist[0][i] < min(dist[1][i], dist[2][i]))
            count++;
    }

    cout << count;
}