#include <iomanip>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, L, W, H;
    cin >> N >> L >> W >> H;

    double start = 0;
    double end = 1'000'000'000;
    double mid;

    for (int i = 0; i < 60; i++) {
        mid = (start + end) / 2;

        if (ll(L / mid) * ll(W / mid) * ll(H / mid) >= N) {
            start = mid;
        } else {
            end = mid;
        }
    }

    cout << fixed << setprecision(10) << end;
}