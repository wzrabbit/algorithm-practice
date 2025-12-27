#include <iostream>
typedef long long ll;
using namespace std;

ll responses[101];
ll answer[101];

ll get_gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return get_gcd(b, a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N - 2; i += 3) {
            cout << "? " << i << ' ' << i + 1 << endl;
            cin >> responses[i];

            cout << "? " << i + 1 << ' ' << i + 2 << endl;
            cin >> responses[i + 1];

            answer[i + 1] = get_gcd(responses[i], responses[i + 1]);
            answer[i] = responses[i] / answer[i + 1];
            answer[i + 2] = responses[i + 1] / answer[i + 1];
        }

        for (int i = N / 3 * 3 + 1; i <= N; i++) {
            cout << "? " << 1 << ' ' << i << endl;
            ll cur;
            cin >> cur;
            answer[i] = cur / answer[1];
        }

        cout << "! ";

        for (int i = 1; i <= N; i++) {
            cout << answer[i] << ' ';
        }

        cout << endl;
    }
}
