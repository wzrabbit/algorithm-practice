#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

struct loc
{
    ll node, val;
};

int visited[1002];
ll num[1002];
vector<vector<int>> graph(1002);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, q;
    cin >> v >> q;

    for (int i = 1; i <= v; i++)
        cin >> num[i];

    for (int i = 1; i <= v - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= q; i++)
    {
        int start, end;
        cin >> start >> end;

        fill(visited, visited + 1001, false);

        queue<loc> que;
        que.push({start, num[start]});
        visited[start] = true;

        while (que.size())
        {
            ll node = que.front().node;
            ll val = que.front().val;
            que.pop();

            if (node == end)
            {
                cout << val << '\n';
                break;
            }

            for (int i = 0; i < graph[node].size(); i++)
            {
                ll next_node = graph[node][i];
                ll next_val = num[graph[node][i]];

                if (visited[next_node] == false)
                {
                    int len = to_string(next_val).length();
                    ll sum_val = val;
                    for (int i = 0; i < len; i++)
                    {
                        sum_val *= 10;
                        sum_val %= 1000000007;
                    }
                    sum_val = (sum_val + next_val) % 1000000007;

                    visited[next_node] = true;
                    que.push({next_node, sum_val});
                }
            }
        }
    }
}