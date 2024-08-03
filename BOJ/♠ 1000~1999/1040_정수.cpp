#include <algorithm>
#include <iostream>
#include <string>
#define INF 8'999'999'999'999'999'999
typedef long long ll;
using namespace std;

ll dp[19][1024][2];
ll digit[19];

ll get_init_value(string S, ll K) {
    ll D = S.size() + 1;
    string value = "";

    if (K == 1) {
        for (int i = 0; i < D; i++) {
            value += "1";
        }

        return stoll(value);
    }

    D = max(D, K);
    value = "1";

    for (int i = 0; i < D - 1; i++) {
        value += "0";
    }

    ll cur_digit = K - 1;

    for (int i = D - 1; i >= 0; i--) {
        if (cur_digit <= 1) {
            break;
        }

        value[i] = '0' + cur_digit;
        cur_digit -= 1;
    }

    return stoll(value);
}

ll get_bit_count(ll num) {
    ll bit_count = 0;

    while (num > 0) {
        bit_count += num % 2;
        num /= 2;
    }

    return bit_count;
}

int main() {
    ll N, K;
    cin >> N >> K;
    N -= 1;

    string S = to_string(N);

    for (size_t i = 0; i < S.size(); i++) {
        digit[i + 1] = S[i] - '0';
    }

    fill(&dp[0][0][0], &dp[18][1023][2], INF);
    dp[0][0][0] = 0;

    for (ll i = 0; i < S.size(); i++) {
        for (ll j = 0; j < 1024; j++) {
            for (ll k = 0; k < 2; k++) {
                if (dp[i][j][k] == INF) {
                    continue;
                }

                for (ll l = 0; l < 10; l++) {
                    if (k == 0 && l < digit[i + 1]) {
                        continue;
                    }

                    ll next_number = dp[i][j][k] * 10 + l;
                    ll next_bit = j | (1 << l);
                    bool is_larger = k | (l > digit[i + 1]);
                    dp[i + 1][next_bit][is_larger] = min(next_number, dp[i + 1][next_bit][is_larger]);
                }
            }
        }
    }

    ll answer = get_init_value(S, K);
    for (ll i = 0; i < 1024; i++) {
        if (get_bit_count(i) != K) {
            continue;
        }

        answer = min(answer, dp[S.size()][i][1]);
    }

    cout << answer;
}
