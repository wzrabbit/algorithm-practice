#include <iostream>
#define MOD 998'244'353
typedef long long ll;
using namespace std;

ll answer[2501];
ll init_value;
ll unit_value = 0;
ll cur_value = 0;
ll id = 0;
ll N;

ll get_pow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }

    ll half = get_pow(x, y / 2);

    if (y % 2 == 0) {
        return half * half % MOD;
    }

    return half * half % MOD * x % MOD;
}

ll get_modular_inverse(ll value, ll divisor) {
    return value * get_pow(divisor, MOD - 2) % MOD;
}

void ask_question(int no) {
    cout << "? ";

    for (int i = 1; i <= N; i++) {
        if (i == no && i >= 3) {
            cout << (id - 1) << ' ';
        } else {
            cout << id << ' ';
        }

        id += 2;
    }

    cout << endl;
}

void handle_response(int no) {
    ll response;
    cin >> response;

    if (no == 1) {
        init_value = response;
        return;
    }

    if (no == 2) {
        cur_value = response;
        unit_value = (cur_value + MOD - init_value) % MOD;
        return;
    }

    cur_value = (cur_value + unit_value) % MOD;
    answer[no] = (cur_value + MOD - response) % MOD;
}

void calculate_first_value() {
    ll rest = 0;

    for (int i = 2; i <= N; i++) {
        rest = (rest + answer[i] * (N + i - 1) * 2) % MOD;
    }

    ll sub = (init_value + unit_value + MOD - rest) % MOD;
    ll div = N * 2;

    answer[1] = get_modular_inverse(sub, div);
}

void calculate_second_value() {
    ll rest = 0;

    for (int i = 3; i <= N; i++) {
        rest = (rest + answer[i] * (i - 1) * 2) % MOD;
    }

    ll sub = (init_value + MOD - rest) % MOD;
    answer[2] = get_modular_inverse(sub, 2);
}

void print_answer() {
    cout << "! ";

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << ' ';
    }

    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        ask_question(i);
        handle_response(i);
    }

    calculate_second_value();
    calculate_first_value();
    print_answer();
}
