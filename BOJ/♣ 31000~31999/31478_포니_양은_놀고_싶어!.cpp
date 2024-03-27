#include <iostream>
typedef long long ll;
using namespace std;

int period[7] = {-1, 1, 3, 6, 3, 6, 2};

ll get_pow(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }

    ll half = get_pow(x, y / 2, mod);

    if (y % 2 == 1) {
        return half * half % mod * x % mod;
    }

    return half * half % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll A, B, C, K, L;
    cin >> A >> B >> C >> K >> L;

    bool is_answer_1_correct = L == (K + get_pow(A, get_pow(B, C, period[A]), 7)) % 7;
    bool is_answer_2_correct = ((L + 7 - K) % 7) * A % 7 == get_pow(B, C, 7);

    ll result = 0;

    if (is_answer_1_correct) {
        result |= 1;
    }

    if (is_answer_2_correct) {
        result |= 2;
    }

    cout << result;
}
