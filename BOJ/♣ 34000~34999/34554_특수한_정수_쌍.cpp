#include <iostream>
using namespace std;

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (is_prime(N + 1)) {
            cout << 1 << '\n' << 1 << ' ' << N + 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
