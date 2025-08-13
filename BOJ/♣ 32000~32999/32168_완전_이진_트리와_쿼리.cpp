#include <iostream>
typedef long long ll;
using namespace std;

ll N, Q;
ll root = 1;

int get_child_direction(ll parent, ll child) {
    ll left = parent;
    ll right = parent;

    if (parent == child) {
        return 0;
    }

    while (true) {
        left = left * 2;
        right = right * 2 + 1;
        ll mid = (left + right) / 2;

        if (child >= left && child <= mid) {
            return 1;
        }

        if (child > mid && child <= right) {
            return 2;
        }

        if (left > N) {
            return -1;
        }
    }
}

ll get_subtree_sum(ll node) {
    ll sum = node;
    ll left = node;
    ll right = node;

    while (true) {
        left = left * 2;
        right = right * 2 + 1;

        ll node_count = max(0ll, min(right, N) - left + 1);
        sum += node_count * (node_count - 1) / 2 + left * node_count;

        if (node_count == 0) {
            break;
        }
    }

    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    while (Q--) {
        ll query_no, value;
        cin >> query_no >> value;

        if (query_no == 1) {
            root = value;
            continue;
        }

        int child_direction = get_child_direction(value, root);

        if (child_direction == 0) {
            cout << get_subtree_sum(1) << '\n';
            continue;
        }

        if (child_direction == 1) {
            cout << get_subtree_sum(1) - get_subtree_sum(value * 2) << '\n';
            continue;
        }

        if (child_direction == 2) {
            cout << get_subtree_sum(1) - get_subtree_sum(value * 2 + 1) << '\n';
            continue;
        }

        cout << get_subtree_sum(value) << '\n';
    }
}
