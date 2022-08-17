#include <algorithm>
#include <iostream>
#include <queue>
#define VAL_SIZE 65537
typedef long long ll;
using namespace std;

int segtree[VAL_SIZE * 4];
queue<int> q;
int N, K;

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

int get_mid(int start, int end, int idx, int target) {
    if (start == end)
        return start;

    int mid = (start + end) / 2;
    int left = segtree[idx * 2 + 1];

    if (target <= left)
        return get_mid(start, mid, idx * 2 + 1, target);
    else
        return get_mid(mid + 1, end, idx * 2 + 2, target - left);
}

void add_queue(int value) {
    q.push(value);
    update(0, VAL_SIZE - 1, 0, value, 1);

    if (q.size() > K) {
        int popped = q.front();
        q.pop();
        update(0, VAL_SIZE - 1, 0, popped, -1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    ll total = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        add_queue(x);
        if (i >= K - 1)
            total += (ll)get_mid(0, VAL_SIZE - 1, 0, (K + 1) / 2);
    }

    cout << total;
}