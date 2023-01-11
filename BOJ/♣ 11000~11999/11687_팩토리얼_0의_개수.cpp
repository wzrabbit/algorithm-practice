#include <iostream>
typedef long long ll;
using namespace std;

ll get_zero_count(ll num) {
    ll count = 0;
    for (ll i = 5; i <= num; i *= 5) {
        count += num / i;
    }
    return count;
}

int main() {
    ll N;
    cin >> N;

    ll left = 1;
    ll right = 1000000000;
    ll mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (get_zero_count(mid) >= N) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (get_zero_count(left) == N) {
        cout << left;
    } else {
        cout << -1;
    }
}