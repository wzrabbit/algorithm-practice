#include <iostream>
typedef long long ll;
using namespace std;

ll raw[1000001];
ll seg_tree[4000001];
ll lazy[4000001];

ll make_seg_tree(int start, int end, int index) {
    if (start == end) {
        return seg_tree[index] = raw[start];
    }

    int mid = (start + end) / 2;
    return seg_tree[index] = make_seg_tree(start, mid, index * 2) +
                             make_seg_tree(mid + 1, end, index * 2 + 1);
}

void propagate(int start, int end, int index) {
    if (lazy[index] == 0) {
        return;
    }

    seg_tree[index] += (end - start + 1) * lazy[index];

    if (start != end) {
        lazy[index * 2] += lazy[index];
        lazy[index * 2 + 1] += lazy[index];
    }

    lazy[index] = 0;
}

void update(int start, int end, int index, int left, int right, ll value) {
    propagate(start, end, index);

    if (end < left || start > right) {
        return;
    }

    if (start >= left && end <= right) {
        seg_tree[index] += (end - start + 1) * value;

        if (start != end) {
            lazy[index * 2] += value;
            lazy[index * 2 + 1] += value;
        }

        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index * 2, left, right, value);
    update(mid + 1, end, index * 2 + 1, left, right, value);
    seg_tree[index] = seg_tree[index * 2] + seg_tree[index * 2 + 1];
}

ll get_sum(int start, int end, int index, int left, int right) {
    propagate(start, end, index);

    if (end < left || start > right) {
        return 0;
    }

    if (start >= left && end <= right) {
        return seg_tree[index];
    }

    int mid = (start + end) / 2;
    return get_sum(start, mid, index * 2, left, right) +
           get_sum(mid + 1, end, index * 2 + 1, left, right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;
    int Q = M + K;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
    }

    make_seg_tree(1, N, 1);

    while (Q--) {
        int q;
        cin >> q;

        if (q == 1) {
            ll start, end, value;
            cin >> start >> end >> value;
            update(1, N, 1, start, end, value);

            continue;
        }

        ll start, end;
        cin >> start >> end;
        cout << get_sum(1, N, 1, start, end) << '\n';
    }
}