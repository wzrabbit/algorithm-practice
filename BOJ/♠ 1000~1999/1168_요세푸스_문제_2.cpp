#include <algorithm>
#include <iostream>
using namespace std;

int segtree[400000];

int make_segtree(int start, int end, int idx) {
    if (start == end)
        return segtree[idx] = 1;

    int mid = (start + end) / 2;
    return segtree[idx] =
               make_segtree(start, mid, idx * 2 + 1) +
               make_segtree(mid + 1, end, idx * 2 + 2);
}

int get_sum(int start, int end, int idx, int left, int right) {
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return segtree[idx];

    int mid = (start + end) / 2;
    return get_sum(start, mid, idx * 2 + 1, left, right) +
           get_sum(mid + 1, end, idx * 2 + 2, left, right);
}

void update(int start, int end, int idx, int target, int value) {
    if (target < start || target > end)
        return;

    segtree[idx] += value;

    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(start, mid, idx * 2 + 1, target, value);
    update(mid + 1, end, idx * 2 + 2, target, value);
}

int get_nth_index(int start, int end, int idx, int target) {
    if (start == end)
        return start;

    int left = segtree[idx * 2 + 1];
    int mid = (start + end) / 2;

    if (target <= left)
        return get_nth_index(start, mid, idx * 2 + 1, target);
    else
        return get_nth_index(mid + 1, end, idx * 2 + 2, target - left);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X;
    cin >> N >> X;
    int target = X - 1;

    make_segtree(0, N - 1, 0);
    cout << '<';

    for (int i = 1; i <= N; i++) {
        cout << target + 1;
        update(0, N - 1, 0, target, -1);

        if (i <= N - 1) {
            int left = get_sum(0, N - 1, 0, 0, target);
            int nxt = (X + left - 1) % (N - i) + 1;
            target = get_nth_index(0, N - 1, 0, nxt);
            cout << ", ";
        }
    }

    cout << '>';
}