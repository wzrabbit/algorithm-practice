#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Edge {
    int start, end, xor_;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.xor_ > b.xor_;
}

int parent[2001];
int point[2001];
vector<Edge> edge;

int get_parent(int child) {
    if (parent[child] == 0) return child;
    return parent[child] = get_parent(parent[child]);
}

bool merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) return false;

    parent[a] = b;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> point[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            edge.push_back({i, j, point[i] ^ point[j]});
        }
    }

    sort(edge.begin(), edge.end());

    ll score = 0;
    int qualified = 0;
    int edge_index = 0;

    while (qualified < N - 1) {
        Edge cur = edge[edge_index++];

        if (!merge(cur.start, cur.end)) {
            continue;
        }

        score += (ll)cur.xor_;
        qualified += 1;
    }

    cout << score;
}