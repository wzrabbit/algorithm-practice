#include <iostream>
using namespace std;

int raw[500000];
int seg_tree[2000000];
int lazy[2000000];

int make_seg_tree(int start, int end, int index) {
    if (start == end) return seg_tree[index] = raw[end];

    int mid = (start + end) / 2;
    return seg_tree[index] = make_seg_tree(start, mid, index * 2 + 1) ^
                             make_seg_tree(mid + 1, end, index * 2 + 2);
}

void propagate(int start, int end, int index) {
    if ((end - start + 1) % 2 == 1) {
        seg_tree[index] ^= lazy[index];
    }

    if (start != end) {
        lazy[index * 2 + 1] ^= lazy[index];
        lazy[index * 2 + 2] ^= lazy[index];
    }

    lazy[index] = 0;
}

void update(int start, int end, int index, int left, int right, int value) {
    propagate(start, end, index);

    if (end < left || start > right) return;

    if (start >= left && end <= right) {
        if ((end - start + 1) % 2 == 1) {
            seg_tree[index] ^= value;
        }

        if (start != end) {
            lazy[index * 2 + 1] ^= value;
            lazy[index * 2 + 2] ^= value;
        }

        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index * 2 + 1, left, right, value);
    update(mid + 1, end, index * 2 + 2, left, right, value);
    seg_tree[index] = seg_tree[index * 2 + 1] ^ seg_tree[index * 2 + 2];
}

int get_xor(int start, int end, int index, int left, int right) {
    propagate(start, end, index);

    if (end < left || start > right) return 0;

    if (start >= left && end <= right) return seg_tree[index];

    int mid = (start + end) / 2;

    return get_xor(start, mid, index * 2 + 1, left, right) ^
           get_xor(mid + 1, end, index * 2 + 2, left, right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> raw[i];
    }

    make_seg_tree(0, N - 1, 0);

    int Q;
    cin >> Q;

    while (Q--) {
        int q;
        cin >> q;

        if (q == 1) {
            int left, right, value;
            cin >> left >> right >> value;

            update(0, N - 1, 0, left, right, value);

            continue;
        }

        int left, right;
        cin >> left >> right;

        cout << get_xor(0, N - 1, 0, left, right) << '\n';
    }
}