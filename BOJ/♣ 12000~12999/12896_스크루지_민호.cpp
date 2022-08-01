#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int max_node;
int max_dist;

void dfs(int cur, int dist)
{
    visited[cur] = true;
    if (max_dist < dist)
    {
        max_node = cur;
        max_dist = dist;
    }

    for (size_t i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (visited[next])
            continue;

        dfs(next, dist + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    max_node = 1;
    max_dist = 0;
    dfs(1, 0);

    fill(&visited[1], &visited[N + 1], false);
    max_dist = 0;
    dfs(max_node, 0);

    if (max_dist % 2 == 1)
        max_dist++;

    cout << max_dist / 2;
}