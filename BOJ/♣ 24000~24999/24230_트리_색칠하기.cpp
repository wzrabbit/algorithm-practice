#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[200001];
int color[200001];
bool visited[200001];
int need = 0;

void dfs(int cur, int parent_color)
{
    visited[cur] = true;
    if (color[cur] != parent_color)
        need++;

    for (size_t i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!visited[next])
            dfs(next, color[cur]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> color[i];

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    cout << need;
}