#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

ll graph[10][10];
vector<ll> permutation;
int V, E;

ll get_dist() {
    ll dist = 0;

    dist += graph[0][permutation[0]];

    for (int i = 0; i < V - 1; i++) {
        ll from = permutation[i];
        ll to = permutation[i + 1];

        dist += graph[from][to];
    }

    dist += graph[permutation[V - 1]][0];

    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    fill(&graph[0][0], &graph[V][V + 1], -INF);

    for (int i = 1; i <= E; i++) {
        ll s, e, d;
        cin >> s >> e >> d;

        graph[s][e] = max(graph[s][e], d);
    }

    for (int i = 1; i <= V; i++) {
        permutation.push_back(i);
    }

    ll answer = -1;

    do {
        answer = max(answer, get_dist());
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << answer;
}
