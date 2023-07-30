#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int visited_order[100001];
int id = 1;

void dfs(int node) {
    visited_order[node] = id++;
    visited[node] = true;

    for (size_t i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];

        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    int V, E, start;
    cin >> V >> E >> start;

    for (int i = 1; i <= E; i++) {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 1; i <= V; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    
    for (int i = 1; i <= V; i++) {
        cout << visited_order[i] << '\n';
    }
}