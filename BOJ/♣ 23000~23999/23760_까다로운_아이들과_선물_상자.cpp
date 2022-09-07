#include <algorithm>
#include <iostream>
using namespace std;

int need[100000];
int kind[100000];
int segtree[4000004];

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

int get_nth_value(int start, int end, int idx, int target) {
    if (start == end)
        return start;

    int mid = (start + end) / 2;
    int right = segtree[idx * 2 + 2];

    if (target <= right)
        return get_nth_value(mid + 1, end, idx * 2 + 2, target);
    else
        return get_nth_value(start, mid, idx * 2 + 1, target - right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    bool success = true;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        update(0, 1000000, 0, x, 1);
    }

    for (int i = 0; i < Q; i++) {
        cin >> need[i];
    }

    for (int i = 0; i < Q; i++) {
        cin >> kind[i];
    }

    for (int i = 0; i < Q; i++) {
        int nth = get_nth_value(0, 1000000, 0, kind[i]);
        int after = nth - need[i];

        if (after < 0) {
            success = false;
            break;
        }

        update(0, 1000000, 0, nth, -1);
        update(0, 1000000, 0, after, 1);
    }

    if (success)
        cout << 1;
    else
        cout << 0;
}