#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define INF 100'000'000'000
typedef long long ll;
using namespace std;

vector<ll> permutation;

int main() {
    string str_N;
    cin >> str_N;

    ll N = stoll(str_N);

    for (int i = 0; i < 10; i++) {
        permutation.push_back(i);
    }

    int digit_count = str_N.length();
    ll answer = -1;
    ll gap = -1;
    ll pow_value = 1;

    for (int i = 0; i < digit_count; i++) {
        pow_value *= 10;
    }

    do {
        ll cur = 0;

        for (int i = 0; i < digit_count; i++) {
            cur *= 10;
            cur += permutation[i];
        }

        ll cur_gap = min(abs(cur - N), pow_value - abs(cur - N));

        if (cur_gap > gap) {
            answer = cur;
            gap = cur_gap;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    string answer_str = to_string(answer);

    if (digit_count != answer_str.length()) {
        cout << '0';
    }

    cout << answer_str;
}
