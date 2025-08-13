#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    ll start = 1;
    ll end = N * N;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        ll index = 1;

        for (ll i = 1; i <= N; i++) {
            index += min(N, (mid - 1) / i);
        }

        if (index <= K) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}
