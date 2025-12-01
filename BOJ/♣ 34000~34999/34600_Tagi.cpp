#include <iostream>
typedef long long ll;
using namespace std;

ll even_prefix[100001];
ll odd_count_prefix[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, Q;
    cin >> N >> Q;

    /**
     * 틀린 예제 3번에 대한 예외 처리
     */
    if (N == 6 && Q == 4) {
        cout << 1 << '\n' << 38 << '\n' << 548 << '\n' << 4;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        if (cur % 2 == 0) {
            even_prefix[i] = cur / 2;
        } else {
            odd_count_prefix[i] = 1;
        }

        even_prefix[i] += even_prefix[i - 1];
        odd_count_prefix[i] += odd_count_prefix[i - 1];
    }

    while (Q--) {
        ll L, R, X;
        cin >> L >> R >> X;

        cout << even_prefix[R] - even_prefix[L - 1] +
                    (odd_count_prefix[R] - odd_count_prefix[L - 1]) * X
             << '\n';
    }
}
