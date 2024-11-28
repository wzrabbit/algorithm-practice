#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

bool is_prime[5000001];
int prefix[5000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    fill(is_prime + 1, is_prime + N + 1, true);

    for (ll i = 2; i * i <= N; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (ll j = i * 2; j <= N; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 1; i <= N; i++) {
        prefix[i] += prefix[i - 1] + is_prime[i];
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        cout << prefix[R] - prefix[L - 1] << '\n';
    }
}
