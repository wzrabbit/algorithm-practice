#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll pins[2001];
ll pillars[40001];
vector<ll> pin_sizes;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll A, B, L;
    cin >> A >> B >> L;

    L *= 2;

    for (int i = 1; i <= A; i++) {
        cin >> pins[i];
    }

    for (int i = 1; i <= B; i++) {
        cin >> pillars[i];
    }

    for (int i = 1; i <= A - 1; i++) {
        for (int j = i + 1; j <= A; j++) {
            pin_sizes.push_back(abs(pins[i] - pins[j]));
        }
    }

    sort(pin_sizes.begin(), pin_sizes.end());

    ll best_height = -1;

    for (int i = 1; i <= B; i++) {
        ll start = 0;
        ll end = (ll)pin_sizes.size() - 1;
        ll mid;

        while (start <= end) {
            mid = (start + end) / 2;
            ll area = pillars[i] * pin_sizes[mid];

            if (area <= L) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (end != -1) {
            best_height = max(best_height, pin_sizes[end] * pillars[i]);
        }
    }

    if (best_height == -1) {
        cout << -1;
        return 0;
    }

    if (best_height % 2 == 0) {
        cout << best_height / 2 << ".0";
    } else {
        cout << best_height / 2 << ".5";
    }
}
