#include <algorithm>
#include <iostream>
using namespace std;

bool is_prime[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fill(is_prime + 2, is_prime + 1000001, true);

    for (int i = 2; i <= 1000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            is_prime[j] = false;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int answer = 0;

        for (int i = 2; i <= N / 2; i++) {
            if (is_prime[i] && is_prime[N - i]) {
                answer += 1;
            }
        }

        cout << answer << '\n';
    }
}
