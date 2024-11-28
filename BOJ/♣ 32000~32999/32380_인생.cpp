#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll A[300001];
ll B[300001];
vector<ll> vec[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, U, D;
    cin >> N >> U >> D;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    ll a_count = 0;
    ll b_count = 0;
    ll a_strength = 0;
    ll b_strength = 0;
    ll risk = U + D;
    ll pure_sum = 0;

    for (int i = 1; i <= N; i++) {
        for (size_t j = 0; j < vec[i].size(); j++) {
            ll cur = vec[i][j];
            pure_sum -= A[cur];
            pure_sum += B[cur];
            a_count -= 1;
            b_count += 1;
            a_strength -= i - cur - 1;
            b_strength += i - cur - 1;
        }

        ll gap = B[i] - A[i];
        ll changing_turn = i + 1 + gap / risk;

        a_strength += a_count;
        b_strength += b_count;

        if (gap < 0) {
            pure_sum += B[i];
            b_count += 1;
        } else {
            pure_sum += A[i];
            a_count += 1;

            if (changing_turn <= N) {
                vec[changing_turn].push_back(i);
            }
        }

        cout << pure_sum + a_strength * U - b_strength * D << '\n';
    }
}
