#include <algorithm>
#include <iostream>
using namespace std;

int loc[100001];
int segtree[800016];

int make_segtree(int start, int end, int idx, int limit) {
    if (start == end) {
        if (start <= limit)
            return segtree[idx] = 1;
        else
            return segtree[idx] = 0;
    }

    int mid = (start + end) / 2;
    return segtree[idx] =
               make_segtree(start, mid, idx * 2, limit) +
               make_segtree(mid + 1, end, idx * 2 + 1, limit);
}

int get_sum(int start, int end, int idx, int left, int right) {
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

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;
        int pointer = N + 1;

        for (int i = 1; i <= N; i++)
            loc[i] = N - i + 1;

        make_segtree(1, N + Q + 1, 1, N);

        for (int i = 0; i < Q; i++) {
            int q;
            cin >> q;

            cout << get_sum(1, N + Q + 1, 1, loc[q] + 1, N + Q + 1) << ' ';
            update(1, N + Q + 1, 1, loc[q], -1);
            loc[q] = pointer++;
            update(1, N + Q + 1, 1, loc[q], 1);
        }

        cout << '\n';
    }
}