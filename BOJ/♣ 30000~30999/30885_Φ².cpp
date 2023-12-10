#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

struct Range {
    int s, e;
};

int parent[500001];
ll scale[500001];
Range range[500001];

int get_parent(int child) {
    if (parent[child] == 0) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b, ll init_scale) {
    a = get_parent(a);
    b = get_parent(b);

    if (init_scale < scale[b]) {
        return;
    }

    parent[b] = a;
    scale[a] += scale[b];

    range[a] = {
        min(range[a].s, range[b].s),
        max(range[a].e, range[b].e)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> scale[i];
        range[i] = {i, i};
    }

    while (true) {
        int index = 1;

        while (index <= N) {
            int cur = get_parent(index);
            ll init_scale = scale[cur];

            if (range[cur].s == 1 && range[cur].e == N) {
                cout << scale[cur] << '\n'
                     << cur;

                return 0;
            }

            if (range[cur].s > 1) {
                int left = get_parent(range[cur].s - 1);
                merge(cur, left, init_scale);
            }

            if (range[cur].e < N) {
                int right = get_parent(range[cur].e + 1);
                merge(cur, right, init_scale);
            }

            index = range[cur].e + 1;
        }
    }
}
