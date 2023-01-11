#include <iostream>
typedef long long ll;
using namespace std;

int N, Q;
ll tree[2000000];

void update(int day, int diff) {
    tree[day + N] += diff;
    for (int i = (day + N) >> 1; i >= 1; i >>= 1) {
        tree[i] += diff;
    }
}

ll get_sum(int start, int end) {
    ll sum = 0;
    int s, e;

    for (s = start + N, e = end + N + 1; s < e; s >>= 1, e >>= 1) {
        if (s & 1) {
            sum += tree[s++];
        }

        if (e & 1) {
            sum += tree[--e];
        }
    }

    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    while (Q--) {
        int q, x, y;
        cin >> q >> x >> y;

        if (q == 1) {
            update(x, y);
        } else {
            cout << get_sum(x, y) << '\n';
        }
    }
}