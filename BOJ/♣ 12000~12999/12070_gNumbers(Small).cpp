#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define EMPTY 0
#define WIN 1
#define LOSE 2
using namespace std;

int dp[1001];
bool is_prime[1001];
vector<int> primes;

bool is_g_number(int num) {
    int sum_digit = 0;
    string stringified_num = to_string(num);

    for (size_t i = 0; i < stringified_num.size(); i++) {
        sum_digit += stringified_num[i] - '0';
    }

    return is_prime[sum_digit] || sum_digit == 1;
}

int get_winner(int num) {
    int &result = dp[num];

    if (result != EMPTY) {
        return result;
    }

    if (is_g_number(num)) {
        return result = LOSE;
    }

    for (size_t i = 0; i < primes.size(); i++) {
        if (primes[i] > num) {
            break;
        }

        if (num % primes[i] != 0) {
            continue;
        }

        int next_num = num;

        while (next_num % primes[i] == 0) {
            next_num /= primes[i];
        }

        if (get_winner(next_num) == LOSE) {
            return result = WIN;
        }
    }

    return result = LOSE;
}

void fill_prime_array() {
    fill(is_prime + 2, is_prime + 1001, true);

    for (int i = 2; i <= 32; i++) {
        if (!is_prime[i]) {
            continue;
        }

        for (int j = i * 2; j <= 1000; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= 1000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    fill_prime_array();

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        cout << "Case #" << t << ": ";

        if (get_winner(N) == WIN) {
            cout << "Laurence";
        } else {
            cout << "Seymour";
        }

        cout << '\n';
    }
}
