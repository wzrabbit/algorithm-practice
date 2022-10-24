#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
using namespace std;

int capacity[401][401];
int flow[401][401];
vector<int> graph[401];

int flow_bfs() {
    int prev[401];
    int total_flow = 0;

    while (true) {
        fill(prev + 1, prev + 401, -1);
        queue<int> q;
        q.push(1);

        while (q.size() && prev[2] == -1) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < graph[cur].size(); i++) {
                int nxt = graph[cur][i];

                if (flow[cur][nxt] < capacity[cur][nxt] && prev[nxt] == -1) {
                    q.push(nxt);
                    prev[nxt] = cur;
                }
            }
        }

        if (prev[2] == -1) break;

        for (int i = 2; i != 1; i = prev[i]) {
            flow[prev[i]][i]++;
            flow[i][prev[i]]--;
        }
        total_flow++;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int s, e;
        cin >> s >> e;
        capacity[s][e] += 1;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    cout << flow_bfs();
}