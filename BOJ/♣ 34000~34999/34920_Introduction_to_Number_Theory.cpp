#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[300001];
ll lcm_prefix[300002];
ll gcd_suffix[300002];

ll get_gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return get_gcd(b, a % b);
}

ll get_lcm(ll a, ll b) { return a * b / get_gcd(a, b); }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + N + 1);

        lcm_prefix[0] = 1;
        gcd_suffix[N + 1] = arr[N];

        for (int i = 1; i <= N; i++) {
            lcm_prefix[i] = get_lcm(lcm_prefix[i - 1], arr[i]);

            if (lcm_prefix[i] > 1'000'000'000) {
                for (int j = i; j <= N; j++) {
                    lcm_prefix[j] = 0;
                }
                break;
            }
        }

        for (int i = N; i >= 1; i--) {
            gcd_suffix[i] = get_gcd(gcd_suffix[i + 1], arr[i]);
        }

        bool success = false;

        for (int i = 1; i <= N - 1; i++) {
            if (lcm_prefix[i] == 0) continue;

            if (lcm_prefix[i] != 0 && gcd_suffix[i + 1] % lcm_prefix[i] == 0) {
                cout << gcd_suffix[i + 1] << '\n';
                success = true;
                break;
            }
        }

        if (!success) {
            cout << -1 << '\n';
        }
    }
}
