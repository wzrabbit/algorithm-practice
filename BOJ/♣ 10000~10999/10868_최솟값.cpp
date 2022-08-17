#include <algorithm>
#include <iostream>
#define INF 1000000001
using namespace std;

int raw[100001];
int segtree[400001];

int make_segtree(int start, int end, int idx) {
    if (start == end)
        return segtree[idx] = raw[start];

    int mid = (start + end) / 2;
    return segtree[idx] = min(
               make_segtree(start, mid, idx * 2),
               make_segtree(mid + 1, end, idx * 2 + 1));
}

int get_min(int start, int end, int idx, int left, int right) {
    if (end < left || right < start)
        return INF;

    if (left <= start && end <= right)
        return segtree[idx];

    int mid = (start + end) / 2;
    return min(get_min(start, mid, idx * 2, left, right),
               get_min(mid + 1, end, idx * 2 + 1, left, right));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> raw[i];

    make_segtree(1, N, 1);

    while (Q--) {
        int s, e;
        cin >> s >> e;
        cout << get_min(1, N, 1, s, e) << '\n';
    }
}