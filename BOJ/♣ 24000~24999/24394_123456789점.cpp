#include <algorithm>
#include <iostream>
#define HALF 500000000
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        ll note, score;
        bool success = false;

        cin >> note >> score;

        ll left = 0;
        ll right = note * 2;
        ll mid;

        while (left <= right) {
            mid = (left + right) / 2;

            ll miss = (note * 2 - mid) / 2;
            ll good = (note * 2 - mid) % 2;
            ll better_than_good = note - miss - good;

            if (mid * HALF / note + better_than_good < score) {
                left = mid + 1;
            } else if (mid * HALF / note > score) {
                right = mid - 1;
            } else {
                success = true;
                ll ans_a = 2 * better_than_good + good;
                ll ans_b = score - mid * HALF / note;
                cout << ans_a << ' ' << ans_b << '\n';
                break;
            }
        }

        if (!success) {
            cout << "-1\n";
        }
    }
}