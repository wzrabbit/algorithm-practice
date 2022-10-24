#include <iostream>
#define INF 4294967296
typedef long long ll;
using namespace std;

bool sieve[100000001];

ll get_biggest(ll x, ll N) {
    ll cur = x;
    while (cur * x <= N) {
        cur *= x;
    }
    return cur;
}

int main() {
    int N;
    cin >> N;
    fill(sieve + 2, sieve + N + 1, true);

    for (int i = 2; i <= 32000; i++) {
        if (!sieve[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            sieve[j] = false;
        }
    }

    ll ans = get_biggest(2, N);
    for (int i = 3; i <= N; i += 2) {
        if (!sieve[i]) continue;
        ans = (ans * get_biggest(i, N)) % INF;
    }

    cout << ans;
}