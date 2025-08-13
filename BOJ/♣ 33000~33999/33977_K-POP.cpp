#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
};

vector<Edge> answer;
int node_count = 9999999;

void simulate(int other, int leaf) {
    vector<Edge> edges;

    if (other + 1 < leaf) {
        return;
    }

    for (int i = 1; i <= other - 1; i++) {
        edges.push_back({i, i + 1});
    }

    for (int i = 1; i <= min(other, leaf); i++) {
        edges.push_back({other - i + 1, other + i});
    }

    if (other < leaf) {
        edges.push_back({other, other + leaf});
    }

    if (other + leaf < node_count) {
        swap(answer, edges);
        node_count = other + leaf;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K;
    cin >> K;

    for (int i = 1; i <= K; i++) {
        if (K % i == 0) {
            simulate(i, K / i);
        }
    }

    cout << node_count << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].u << ' ' << answer[i].v << '\n';
    }
}
