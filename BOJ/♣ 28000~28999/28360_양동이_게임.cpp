#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[51];
double water[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    water[1] = 100;

    for (int i = 1; i <= V; i++) {
        if (graph[i].size() == 0) {
            continue;
        }

        double divided = water[i] / graph[i].size();

        for (size_t j = 0; j < graph[i].size(); j++) {
            water[graph[i][j]] += divided;
        }

        water[i] = 0;
    }

    double best = 0;

    for (int i = 1; i <= V; i++) {
        best = max(best, water[i]);
    }

    cout << fixed << setprecision(7) << best;
}