#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

ll pos = 0;
ll dist = 0;
set<ll> trash_set;

ll get_next_pos() {
    auto lower = trash_set.lower_bound(pos);
    auto upper = lower;

    ll lower_pos = -1, upper_pos = -1;

    if (lower != trash_set.begin()) {
        --lower;
        lower_pos = *lower;
    }

    if (upper != trash_set.end()) {
        upper_pos = *upper;
    }

    if (lower_pos == -1 && upper_pos == -1) {
        return -1;
    }

    if (lower_pos == -1) {
        return upper_pos;
    }

    if (upper_pos == -1) {
        return lower_pos;
    }

    ll lower_gap = abs(pos - lower_pos);
    ll upper_gap = abs(pos - upper_pos);

    if (lower_gap <= upper_gap) {
        return lower_pos;
    }

    return upper_pos;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    while (Q--) {
        ll q, x;
        cin >> q;

        if (q == 1) {
            cin >> x;
            trash_set.insert(x);
            continue;
        }

        while (true) {
            ll next_pos = get_next_pos();

            if (next_pos == -1) {
                break;
            }

            dist += abs(next_pos - pos);
            trash_set.erase(next_pos);
            pos = next_pos;
        }
    }

    cout << dist;
}
