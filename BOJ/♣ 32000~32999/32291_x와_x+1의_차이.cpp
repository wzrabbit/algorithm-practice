#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

struct Factor {
    ll n, c;
};

set<ll> answer;
vector<Factor> factors;

void add_prime_factors(ll num) {
    ll div = 2;

    while (num >= 2 && div * div <= num) {
        if (num % div == 0) {
            factors.push_back({div, 0});

            while (num % div == 0) {
                num /= div;
                factors.back().c += 1;
            }
        }

        div += 1;
    }

    if (num != 1) {
        factors.push_back({num, 1});
    }
}

void generate_answer(ll limit) {
    ll repeat = 1;

    for (size_t i = 0; i < factors.size(); i++) {
        repeat *= (factors[i].c + 1);
    }

    for (int i = 0; i < repeat; i++) {
        ll cur = 1;
        ll bit = i;

        for (size_t j = 0; j < factors.size(); j++) {
            ll mul = bit % (factors[j].c + 1);
            bit /= (factors[j].c + 1);

            for (int k = 1; k <= mul; k++) {
                cur *= factors[j].n;
            }
        }

        if (cur <= limit) {
            answer.insert(cur);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;

    add_prime_factors(N + 1);
    generate_answer(N);

    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << ' ';
    }
}
