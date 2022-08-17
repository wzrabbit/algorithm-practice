#include <algorithm>
#include <iostream>
using namespace std;

int raw[1000000];
int segtree[4000000];

int make_segtree(int start, int end, int idx) {
    if (start == end)
        return segtree[idx] = raw[start];

    int mid = (start + end) / 2;
    return segtree[idx] = max(
               make_segtree(start, mid, idx * 2 + 1),
               make_segtree(mid + 1, end, idx * 2 + 2));
}

int get_max(int start, int end, int idx, int left, int right) {
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return segtree[idx];

    int mid = (start + end) / 2;
    return max(
        get_max(start, mid, idx * 2 + 1, left, right),
        get_max(mid + 1, end, idx * 2 + 2, left, right));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, R;
    cin >> N >> R;
    R = R * 2 - 1;

    for (int i = 0; i < N; i++)
        cin >> raw[i];

    make_segtree(0, N - 1, 0);

    for (int i = 0; i < N - R + 1; i++)
        cout << get_max(0, N - 1, 0, i, i + R - 1) << '\n';
}