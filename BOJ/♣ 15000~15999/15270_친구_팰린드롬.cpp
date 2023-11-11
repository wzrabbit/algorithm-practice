#include <algorithm>
#include <iostream>
using namespace std;

bool graph[20][20];
bool visited[2 << 20];
int V, E;

void dfs(int bit) {
    visited[bit] = true;

    for (int i = 0; i < V - 1; i++) {
        for (int j = i + 1; j < V; j++) {
            if ((bit & (1 << i)) == 0 && (bit & (1 << j)) == 0 && graph[i][j]) {
                int new_bit = bit | (1 << i) | (1 << j);

                if (!visited[new_bit]) {
                    dfs(new_bit);
                }
            }
        }
    }
}

int count_one_bits(int bit) {
    int one_bit_count = 0;

    while (bit > 0) {
        one_bit_count += bit & 1;
        bit >>= 1;
    }

    return one_bit_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;

        if (u > v) {
            swap(u, v);
        }

        u -= 1;
        v -= 1;

        graph[u][v] = true;
    }

    dfs(0);

    int best = 0;

    for (int i = 0; i < (1 << V); i++) {
        if (visited[i]) {
            best = max(best, count_one_bits(i));
        }
    }

    if (best != V) {
        best += 1;
    }

    cout << best;
}