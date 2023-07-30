#include <iostream>
typedef long long ll;
using namespace std;

ll find_N(ll sum) {
    ll start = 1;
    ll end = 1999999;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        ll current_sum = mid * (mid + 1) / 2;

        if (current_sum > sum) {
            end = mid - 1;
        } else if (current_sum < sum) {
            start = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll X, Y;
    cin >> X >> Y;

    ll N = find_N(X + Y);

    if (N == -1) {
        cout << -1;
        return 0;
    }

    ll win_count = 0;

    while (X > 0) {
        X -= N;
        N -= 1;
        win_count += 1;
    }

    cout << win_count;
}