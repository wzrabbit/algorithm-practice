#include <iostream>
using namespace std;

int arr[200001];
bool is_prime[1000001];

void make_sieve() {
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

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    bool is_sorted = true;

    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[i + 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        cout << "YES";
        return 0;
    }

    make_sieve();

    bool success = false;

    for (int i = 1; i < N; i++) {
        if (arr[i] != 1 && arr[i + 1] != 1) {
            success = true;
            break;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] != 1 && !is_prime[arr[i]]) {
            success = true;
            break;
        }
    }

    if (success) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
