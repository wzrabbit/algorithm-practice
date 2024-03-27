#include <algorithm>
#include <iostream>
#define SQRT 32
using namespace std;

bool is_prime[1001];

void make_prime_list() {
    fill(is_prime + 2, is_prime + 1001, true);

    for (int i = 2; i <= SQRT; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 1000; j += i) {
            is_prime[j] = false;
        }
    }
}

void handle_case_1(int N) {
    int first_odd = (N % 4 == 0) ? N - 1 : N - 3;
    int second_odd = 2 * N - 4 - first_odd;

    for (int i = first_odd; i >= 1; i -= 4) {
        cout << i << ' ';
    }

    for (int i = second_odd; i >= 1; i -= 4) {
        cout << i << ' ';
    }

    for (int i = N; i >= 1; i -= 4) {
        cout << i << ' ';
    }

    for (int i = N - 2; i >= 1; i -= 4) {
        cout << i << ' ';
    }
}

void handle_case_2(int N) {
    int first_odd = (N % 4 == 3) ? N - 4 : N - 2;
    int second_odd = 2 * N - 6 - first_odd;

    for (int i = first_odd; i >= 1; i -= 4) {
        cout << i << ' ';
    }

    for (int i = second_odd; i >= 1; i -= 4) {
        cout << i << ' ';
    }

    cout << N << ' ';

    for (int i = 2; i <= N; i += 4) {
        cout << i << ' ';
    }

    for (int i = 4; i <= N; i += 4) {
        cout << i << ' ';
    }
}
void handle_case_3(int N) {
    cout << N - 1 << ' ' << N << ' ';
    handle_case_2(N - 2);
}

void handle_case_4(int N) {
    for (int i = 10; i <= N - 6; i += 4) {
        cout << i << ' ';
    }

    for (int i = 4; i <= N - 6; i += 4) {
        cout << i << ' ';
    }

    cout << 2 << ' ' << N - 5 << ' ' << 1 << ' ';

    for (int i = N - 2; i >= 3; i -= 4) {
        cout << i << ' ';
    }

    for (int i = N - 4; i >= 3; i -= 4) {
        cout << i << ' ';
    }

    cout << N << ' ' << N - 1 << ' ' << 6 << ' ' << N - 3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N == 2) {
        cout << "YES\n1 2";
        return 0;
    }

    make_prime_list();

    if (N <= 9 || is_prime[N - 1]) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    if (N % 2 == 0) {
        handle_case_1(N);
    } else if (!is_prime[N - 2]) {
        handle_case_2(N);
    } else if (!is_prime[N - 4]) {
        handle_case_3(N);
    } else {
        handle_case_4(N);
    }
}
