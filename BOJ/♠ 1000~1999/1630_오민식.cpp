#include <algorithm>
#include <iostream>
#define SQRT 1'000
#define MOD 987'654'321
typedef long long ll;
using namespace std;

bool is_prime[1000001];

int main() {
    int N;
    cin >> N;

    fill(is_prime + 2, is_prime + N + 1, true);

    for (int i = 2; i <= SQRT; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }

    ll answer = 1;

    for (int i = 2; i <= 1000000; i++) {
        if (!is_prime[i]) {
            continue;
        }

        ll cur = 1;

        while (cur * i <= N) {
            cur *= i;
        }

        answer = answer * cur % MOD;
    }

    cout << answer;
}