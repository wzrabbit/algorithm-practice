#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int parent[200001];
int scale[200001];
int query[200001];
bool result[200001];
vector<vector<int>> graph(200001);
bool activated[200001];
int biggest = 1;

int get_parent(int child) {
    if (parent[child] == -1)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        if (scale[a] > scale[b]) {
            parent[b] = a;
            scale[a] += scale[b];
            biggest = max(biggest, scale[a]);
        } else {
            parent[a] = b;
            scale[b] += scale[a];
            biggest = max(biggest, scale[b]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    fill(&parent[0], &parent[V + 1], -1);
    fill(&scale[0], &scale[V + 1], 1);

    for (int i = 0; i < E; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 0; i < V; i++)
        cin >> query[i];

    for (int i = V - 1; i >= 0; i--) {
        int s = query[i];
        activated[s] = true;

        for (size_t j = 0; j < graph[s].size(); j++) {
            int e = graph[s][j];
            if (activated[e])
                merge(s, e);
        }

        if (biggest == V - i)
            result[i] = true;
        else
            result[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (result[i] == true)
            cout << "CONNECT\n";
        else
            cout << "DISCONNECT\n";
    }
    cout << "DISCONNECT";
}