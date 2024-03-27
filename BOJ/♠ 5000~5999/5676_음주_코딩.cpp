#include <iostream>
typedef long long ll;
using namespace std;

ll fanwick_tree[100001];
ll N, Q;

ll get_sum_from_start(int index) {
    ll sum = 0;

    while (index >= 1) {
        sum += fanwick_tree[index];
        index -= index & -index;
    }

    return sum;
}

ll get_sum_in_range(int start, int end) {
    return get_sum_from_start(end) - get_sum_from_start(start - 1);
}

char get_multiple_in_range(int start, int end) {
    ll range_sum = get_sum_in_range(start, end);

    if (range_sum >= 1000000) {
        return '0';
    }

    if (range_sum % 2 == 0) {
        return '+';
    }

    return '-';
}

void update(int index, ll value) {
    ll before = get_sum_in_range(index, index);

    while (index <= N) {
        fanwick_tree[index] += -before + value;
        index += index & -index;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> N >> Q;

        if (cin.eof()) {
            return 0;
        }

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            if (cur > 0) {
                cur = 0;
            } else if (cur < 0) {
                cur = 1;
            } else {
                cur = 1000000;
            }

            update(i, cur);
        }

        while (Q--) {
            char q;
            int a, b;
            cin >> q >> a >> b;

            if (q == 'P') {
                cout << get_multiple_in_range(a, b);
                continue;
            }

            if (b > 0) {
                update(a, 0);
            } else if (b < 0) {
                update(a, 1);
            } else {
                update(a, 1000000);
            }
        }

        cout << '\n';
    }
}
