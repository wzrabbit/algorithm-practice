// Code By wizardrabbit - GL HF!

#include <algorithm>
#include <iostream>
using namespace std;

int segtree[400004];
int res[100001];

int make_segtree(int start, int end, int idx) {
    if (start == end)
        return segtree[idx] = 1;

    int mid = (start + end) / 2;
    return segtree[idx] =
               make_segtree(start, mid, idx * 2) +
               make_segtree(mid + 1, end, idx * 2 + 1);
}

int get_sum(int start, int end, int idx, int left, int right) {
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return segtree[idx];

    int mid = (start + end) / 2;
    return segtree[idx] =
               get_sum(start, mid, idx * 2, left, right) +
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

int get_index(int start, int end, int idx, int target) {
    if (start == end)
        return start;

    int left = segtree[idx * 2];
    int mid = (start + end) / 2;

    if (target <= left)
        return get_index(start, mid, idx * 2, target);
    else
        return get_index(mid + 1, end, idx * 2 + 1, target - left);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    make_segtree(1, N, 1);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        int ans_index = get_index(1, N, 1, x + 1);
        res[ans_index] = i;
        update(1, N, 1, ans_index, -1);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';
}