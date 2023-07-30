#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    ll start = 0;
    ll end = N / 2;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        ll calc = (mid + 1) * (N - mid + 1);

        if (calc > K) {
            end = mid - 1;
        } else if (calc < K) {
            start = mid + 1;
        } else {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}