#include <iostream>
#include <string>
#define OPERATION_COUNT 100000000
typedef long long ll;
using namespace std;

bool is_tle_N(ll N, ll T, ll L) { return N * T > L * OPERATION_COUNT; }

bool is_tle_N2(ll N, ll T, ll L) { return N * N * T > L * OPERATION_COUNT; }

bool is_tle_N3(ll N, ll T, ll L) {
    return N >= 10000 || N * N * N * T > L * OPERATION_COUNT;
}

bool is_tle_2N(ll N, ll T, ll L) {
    ll cur = 1;

    for (int i = 1; i <= N; i++) {
        cur *= 2;

        if (cur * T > L * OPERATION_COUNT) {
            return true;
        }
    }

    return false;
}

bool is_tle_factorial(ll N, ll T, ll L) {
    ll cur = 1;

    for (int i = 2; i <= N; i++) {
        cur *= i;

        if (cur * T > L * OPERATION_COUNT) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        string S;
        ll N, T, L;
        cin >> S >> N >> T >> L;
        bool is_tle;

        if (S == "O(N)") {
            is_tle = is_tle_N(N, T, L);
        } else if (S == "O(N^2)") {
            is_tle = is_tle_N2(N, T, L);
        } else if (S == "O(N^3)") {
            is_tle = is_tle_N3(N, T, L);
        } else if (S == "O(2^N)") {
            is_tle = is_tle_2N(N, T, L);
        } else {
            is_tle = is_tle_factorial(N, T, L);
        }

        if (is_tle) {
            cout << "TLE!\n";
        } else {
            cout << "May Pass.\n";
        }
    }
}
