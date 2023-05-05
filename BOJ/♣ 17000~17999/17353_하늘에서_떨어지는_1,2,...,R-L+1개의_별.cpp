#include <iostream>
typedef long long ll;
using namespace std;

ll raw[100001];
ll seg_tree[400001];
ll lazy[400001][2];

ll make_seg_tree(ll start, ll end, ll index) {
    if (start == end) {
        return seg_tree[index] = raw[start];
    }

    ll mid = (start + end) / 2;
    return seg_tree[index] = make_seg_tree(start, mid, index * 2) +
                             make_seg_tree(mid + 1, end, index * 2 + 1);
}

ll get_real_lazy_value(ll start_number, ll plus_count, ll element_count) {
    return start_number * element_count + element_count * (element_count - 1) * plus_count / 2;
}

void propagate(ll start, ll end, ll index) {
    if (lazy[index][0] == 0) {
        return;
    }

    seg_tree[index] += get_real_lazy_value(lazy[index][0], lazy[index][1], end - start + 1);

    if (start != end) {
        ll mid = (start + end) / 2;
        lazy[index * 2][0] += lazy[index][0];
        lazy[index * 2 + 1][0] += lazy[index][0] + (mid - start + 1) * lazy[index][1];
        lazy[index * 2][1] += lazy[index][1];
        lazy[index * 2 + 1][1] += lazy[index][1];
    }

    lazy[index][0] = 0;
    lazy[index][1] = 0;
}

void update(ll start, ll end, ll index, ll left, ll right) {
    propagate(start, end, index);

    if (end < left || start > right) {
        return;
    }

    if (start >= left && end <= right) {
        seg_tree[index] += get_real_lazy_value(start - left + 1, 1, end - start + 1);

        if (start != end) {
            ll mid = (start + end) / 2;

            lazy[index * 2][0] += start - left + 1;
            lazy[index * 2 + 1][0] += start - left + 1 + mid - start + 1;
            lazy[index * 2][1] += 1;
            lazy[index * 2 + 1][1] += 1;
        }

        return;
    }

    ll mid = (start + end) / 2;
    update(start, mid, index * 2, left, right);
    update(mid + 1, end, index * 2 + 1, left, right);
    seg_tree[index] = seg_tree[index * 2] + seg_tree[index * 2 + 1];
}

ll get_value(ll start, ll end, ll index, ll target) {
    propagate(start, end, index);

    if (start == end) {
        return seg_tree[index];
    }

    ll mid = (start + end) / 2;
    if (target <= mid) {
        return get_value(start, mid, index * 2, target);
    } else {
        return get_value(mid + 1, end, index * 2 + 1, target);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
    }

    make_seg_tree(1, N, 1);

    int Q;
    cin >> Q;

    while (Q--) {
        int q;
        cin >> q;

        if (q == 1) {
            ll start, end;
            cin >> start >> end;
            update(1, N, 1, start, end);
        } else {
            ll target;
            cin >> target;
            cout << get_value(1, N, 1, target) << '\n';
        }
    }
}