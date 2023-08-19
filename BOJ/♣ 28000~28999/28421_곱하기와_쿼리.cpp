#include <iostream>
#include <set>
using namespace std;

bool is_zero[100001];
int number_count[10001];
int arr[100001];
int N, Q;

bool is_possible(int n) {
    if (n == 0 && N >= 2 && number_count[0] >= 1) {
        return true;
    }

    for (int i = 1; i * i <= n; i++) {
        if (i * i == n && number_count[i] >= 2) {
            return true;
        }

        if (i * i != n && n % i == 0 && number_count[i] >= 1 && n / i <= 10000 && number_count[n / i] >= 1) {
            return true;
        }
    }

    return false;
}

void remove_number(int n) {
    if (is_zero[n]) {
        return;
    }

    is_zero[n] = true;
    number_count[arr[n]] -= 1;
    number_count[0] += 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        number_count[arr[i]] += 1;
    }

    while (Q--) {
        int q, n;
        cin >> q >> n;

        if (q == 1) {
            cout << is_possible(n) << '\n';
        } else {
            remove_number(n);
        }
    }
}