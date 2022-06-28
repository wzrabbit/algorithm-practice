#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

bool BFS(int start)
{
    if (visited[start] != 0)
        return true;
    queue<int> que;

    que.push(start);

    while (que.size())
    {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nxt = graph[cur][i];

            if (visited[nxt] != 0 && visited[cur] == visited[nxt])
                return false;

            if (!visited[nxt])
            {
                visited[nxt] = 3 - visited[cur];
                que.push(nxt);
            }
        }
    }

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;

    while (T--)
    {
        int V, E, s, e;
        cin >> V >> E;
        graph.clear();
        visited.clear();
        graph.resize(V + 1);
        visited.resize(V + 1);
        bool possible = true;

        for (int i = 0; i < E; i++)
        {
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }

        for (int i = 1; i <= V; i++)
        {
            possible = BFS(i);

            if (!possible)
                break;
        }

        if (possible)
            cout << "possible\n";
        else
            cout << "impossible\n";
    }
}