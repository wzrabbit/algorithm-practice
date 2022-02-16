#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll raw[100001];
ll tree[400001];

ll makeSegTree(int start, int end, int index) {
    if (start == end) {
        tree[index] = raw[start];
        return tree[index];
    }
    int mid = (start + end) / 2;
    tree[index] = makeSegTree(start, mid, index * 2 + 1) + makeSegTree(mid + 1, end, index * 2 + 2);
    return tree[index];
}

ll getSum(int start, int end, int index, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && right >= end) return tree[index];
    int mid = (start + end) / 2;
    return getSum(start, mid, index * 2 + 1, left, right) + getSum(mid + 1, end, index * 2 + 2, left, right);
}

void update(int start, int end, int index, int target, ll increment) {
    if (target > end || target < start) return;
    tree[index] += increment;
    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, index * 2 + 1, target, increment);
        update(mid + 1, end, index * 2 + 2, target, increment);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> raw[i];
    makeSegTree(0, n - 1, 0);

    for (int i = 0; i < q; i++) {
        ll a, b, c, d, gap;
        cin >> a >> b >> c >> d;
        a--; b--; c--;
        if (a > b) swap(a, b);
        cout << getSum(0, n - 1, 0, a, b) << '\n';
        gap = d - raw[c];
        raw[c] = d;
        update(0, n - 1, 0, c, gap);
    }
}