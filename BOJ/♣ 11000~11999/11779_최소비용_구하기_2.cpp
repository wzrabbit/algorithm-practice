#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 10e8 * 2
using namespace std;

struct pq_data
{
    int v, d;
};

struct compare
{
    bool operator()(pq_data a, pq_data b)
    {
        return a.d > b.d;
    }
};

vector<vector<pq_data>> graph;
vector<int> dist;
vector<int> history;
vector<int> path;

void dijkstra(int start_node)
{
    priority_queue<pq_data, vector<pq_data>, compare> pq;
    pq.push({start_node, 0});
    dist[start_node] = 0;

    while (pq.size())
    {
        pq_data current = pq.top();
        pq.pop();

        if (current.d > dist[current.v])
            continue;

        for (int i = 0; i < graph[current.v].size(); i++)
        {
            pq_data next = graph[current.v][i];
            int cost = current.d + next.d;

            if (cost < dist[next.v])
            {
                dist[next.v] = cost;
                pq.push({next.v, cost});
                history[next.v] = current.v;
            }
        }
    }
}

void get_path(int vertex)
{
    if (history[vertex] != -1)
        get_path(history[vertex]);

    path.push_back(vertex);
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    int v, e, st, en, di, start_node, end_node;
    cin >> v >> e;

    graph.resize(v + 1);
    dist.resize(v + 1);
    fill(dist.begin(), dist.end(), INF);
    history.resize(v + 1);

    for (int i = 0; i < e; i++)
    {
        cin >> st >> en >> di;
        graph[st].push_back({en, di});
    }

    cin >> start_node >> end_node;
    history[start_node] = -1;

    dijkstra(start_node);
    get_path(end_node);

    cout << dist[end_node] << '\n';
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << ' ';
}