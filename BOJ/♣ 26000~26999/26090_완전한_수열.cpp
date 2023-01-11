#include <algorithm>
#include <iostream>
#define SQRT 1000
using namespace std;

bool is_prime[1000001];
int arr[501];
int stability = 0;
int N;

void fill_primes() {
    fill(is_prime + 2, is_prime + 1000001, true);

    for (int i = 2; i <= SQRT; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }
}

void find_stable(int len) {
    int sum = 0;
    W for (int i = 1; i <= len; i++) {
        sum += arr[i];
    }

    if (is_prime[sum]) {
        stability += 1;
    }

    for (int i = len + 1; i <= N; i++) {
        sum += arr[i];
        sum -= arr[i - len];

        if (is_prime[sum]) {
            stability += 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    fill_primes();

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        if (!is_prime[i]) {
            continue;
        }

        find_stable(i);
    }

    cout << stability;
}