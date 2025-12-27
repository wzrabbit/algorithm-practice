#include <algorithm>
#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll W_prefix[200001];
ll E_prefix[200001];
char S[200002];
ll mul[200001];

void make_factorial() {
    mul[0] = 1;

    for (int i = 1; i <= 200000; i++) {
        mul[i] = mul[i - 1] * 2 % MOD;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    cin >> (S + 1);

    make_factorial();

    for (int i = 1; i <= N; i++) {
        W_prefix[i] = W_prefix[i - 1] + (S[i] == 'W' ? 1 : 0);
        E_prefix[i] = E_prefix[i - 1] + (S[i] == 'E' ? 1 : 0);
    }

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        if (S[i] != 'H') continue;

        ll cur = (W_prefix[i - 1] * (mul[E_prefix[N] - E_prefix[i]] + MOD -
                                     (E_prefix[N] - E_prefix[i]) - 1)) %
                 MOD;
        answer = (answer + cur) % MOD;
    }

    cout << answer;
}
