#include <algorithm>
#include <iostream>
using namespace std;

bool is_prime[1000001];

void make_prime_array() {
    fill(is_prime + 2, is_prime + 1000001, true);

    for (int i = 2; i <= 1000; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    make_prime_array();

    int N, K;
    cin >> N >> K;

    for (int i = 2; i <= 1000000; i++) {
        if (N == 0) {
            break;
        }

        if (is_prime[i] && i % K == 1) {
            cout << i << ' ';
            N -= 1;
        }
    }
}
