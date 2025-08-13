#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        ll N, A;
        cin >> N >> A;

        ll answer = 0;

        for (ll i = 1; i <= N - 1; i++) {
            for (ll j = 0; j <= i - 1; j++) {
                ll cur_area = i * i - (i - j) * j * 2;

                if (cur_area >= A) {
                    answer += (N - i) * (N - i);
                }
            }
        }

        cout << answer << '\n';
    }
}
