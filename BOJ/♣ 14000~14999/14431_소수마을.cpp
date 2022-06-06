#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define INF 10e8
using namespace std;

struct loc
{
    int x, y;
};

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

vector<loc> vertex;
vector<int> dist;
bool is_prime[9000];

void dijkstra(int v)
{
    priority_queue<pq_data, vector<pq_data>, compare> pq;
    pq.push({0, 0});

    while (pq.size())
    {
        pq_data current = pq.top();
        pq.pop();

        if (current.d > dist[current.v])
            continue;

        for (int i = 0; i < v; i++)
        {
            int x1, y1, x2, y2, next_dist;
            x1 = vertex[current.v].x;
            y1 = vertex[current.v].y;
            x2 = vertex[i].x;
            y2 = vertex[i].y;

            next_dist = (int)sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
            int cost = current.d + next_dist;
            if (is_prime[next_dist] && cost < dist[i])
            {
                dist[i] = cost;
                pq.push({i, cost});
            }
        }
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);
    int x1, y1, x2, y2, v;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> v;
    v += 2;

    vertex.resize(v);
    dist.resize(v);
    fill(dist.begin(), dist.end(), INF);
    dist[0] = 0;

    vertex[0] = {x1, y1};
    for (int i = 1; i < v - 1; i++)
        cin >> vertex[i].x >> vertex[i].y;
    vertex[v - 1] = {x2, y2};

    fill(is_prime, is_prime + 9000, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= 100; i++)
    {
        if (!is_prime[i])
            continue;

        for (int j = i * 2; j < 9000; j += i)
            is_prime[j] = false;
    }

    dijkstra(v);
    if (dist[v - 1] == INF)
        cout << -1;
    else
        cout << dist[v - 1];
}