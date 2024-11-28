#include <iostream>
typedef long long ll;
using namespace std;

struct Population {
    ll m, f;
};

Population populations[100001];
bool is_male[100001];
int parent[100001];
ll pair_count = 0;

int get_parent(int child) {
    if (parent[child] == child) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) {
        return;
    }

    pair_count -= populations[a].m * populations[a].f;
    pair_count -= populations[b].m * populations[b].f;

    parent[b] = a;
    populations[a].m += populations[b].m;
    populations[a].f += populations[b].f;

    pair_count += populations[a].m * populations[a].f;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        is_male[i] = cur % 2;
        parent[i] = i;
        populations[i] = {is_male[i], 1 - is_male[i]};
    }

    while (M--) {
        int a, b;
        cin >> a >> b;

        merge(a, b);

        cout << pair_count << '\n';
    }
}
