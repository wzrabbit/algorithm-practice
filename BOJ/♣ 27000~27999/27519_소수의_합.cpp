#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1'000'000'007
#define MAX_SIZE 100'000
using namespace std;

bool is_prime[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];
vector<int> primes;

void make_dp() {
    fill(is_prime + 2, is_prime + MAX_SIZE + 1, true);

    for (int i = 2; i * i <= MAX_SIZE; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= MAX_SIZE; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= MAX_SIZE; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    dp[0] = 1;

    for (size_t i = 0; i < primes.size(); i++) {
        int cur = primes[i];

        for (int j = cur; j <= MAX_SIZE; j++) {
            dp[j] = (dp[j] + dp[j - cur]) % INF;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    make_dp();

    while (T--) {
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }
}