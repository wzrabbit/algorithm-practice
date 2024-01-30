#include <iostream>
#include <vector>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll connected_count[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        connected_count[u] += 1;
        connected_count[v] += 1;
    }

    ll answer = 0;

    for (int i = 1; i <= V; i++) {
        answer += connected_count[i] * (connected_count[i] - 1) * (connected_count[i] - 2) / 6;
        answer %= MOD;
    }

    cout << answer;
}