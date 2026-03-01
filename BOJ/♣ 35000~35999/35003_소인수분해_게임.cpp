#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;

ll is_prime[1000001];
vector<ll> primes;

void make_primes() {
    fill(is_prime + 2, is_prime + 1000001, true);

    for (int i = 2; i <= 1000; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    make_primes();

    while (T--) {
        ll N;
        cin >> N;

        map<ll, ll> factor_count;
        ll turn_count = 0;
        ll max_number_count = 1;

        for (ll cur : primes) {
            while (N % cur == 0) {
                N /= cur;
                factor_count[cur] += 1;
                max_number_count = max(max_number_count, factor_count[cur]);
                turn_count += 1;
            }
        }

        if (N != 1) {
            turn_count += 1;
        }

        if (max_number_count > (turn_count + 1) / 2) {
            cout << "yyyy7089\n";
            continue;
        }

        cout << (turn_count % 2 == 1 ? "yyyy7089\n" : "toycartoon\n");
    }
}
