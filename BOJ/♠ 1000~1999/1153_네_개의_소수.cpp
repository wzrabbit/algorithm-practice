#include <algorithm>
#include <iostream>
using namespace std;

bool is_prime[1000001];

void make_prime_array() {
    fill(is_prime + 2, is_prime + 1000001, true);

    for (int i = 2; i <= 1000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N <= 7) {
        cout << -1;
        return 0;
    }

    make_prime_array();

    if (N % 2 == 0) {
        for (int i = 1; i <= N - 4; i++) {
            if (is_prime[i] && is_prime[N - 4 - i]) {
                cout << "2 2 " << i << ' ' << N - 4 - i << '\n';
                return 0;
            }
        }
    }

    for (int i = 1; i <= N - 5; i++) {
        if (is_prime[i] && is_prime[N - 5 - i]) {
            cout << "2 3 " << i << ' ' << N - 5 - i << '\n';
            return 0;
        }
    }
}
