#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll raw[500001];
ll segtree[2000004];

ll make_segtree(int start, int end, int idx) {
    if (start == end) {
        return segtree[idx] = raw[start];
    }

    int mid = (start + end) / 2;
    return segtree[idx] =
               make_segtree(start, mid, idx * 2) +
               make_segtree(mid + 1, end, idx * 2 + 1);
}

ll get_sum(int start, int end, int idx, int left, int right) {
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return segtree[idx];

    int mid = (start + end) / 2;
    return get_sum(start, mid, idx * 2, left, right) +
           get_sum(mid + 1, end, idx * 2 + 1, left, right);
}

void update(int start, int end, int idx, int target, int value) {
    if (target < start || target > end)
        return;

    segtree[idx] += value;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(start, mid, idx * 2, target, value);
    update(mid + 1, end, idx * 2 + 1, target, value);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
    }

    make_segtree(1, N, 1);

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        char q;
        int x, y;
        cin >> q >> x >> y;

        if (q == 'U') {
            update(1, N, 1, x, y);
        } else {
            cout << get_sum(1, N, 1, x, y) << '\n';
        }
    }
}