#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

ll get_power(ll power_A, ll cnt_A, ll power_B, ll cnt_B) {
    return power_A * cnt_A + power_B * cnt_B;
}

ll get_cost(ll cnt_A, ll cost_A, ll cnt_B, ll cost_B) {
    return cnt_A * cost_A + cnt_B * cost_B;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll money;
    ll power_A, cost_A, power_B, cost_B;
    cin >> money;
    cin >> power_A >> cost_A >> power_B >> cost_B;

    ll cnt_A = money / cost_A;
    ll cnt_B = 0;
    ll best_power = get_power(power_A, cnt_A, power_B, cnt_B);
    ll best_cnt_A = money / cost_A;
    ll best_cnt_B = 0;

    while (true) {
        if (get_cost(cnt_A, cost_A, cnt_B, cost_B) > money) {
            cnt_A -= 1;
        } else {
            ll cur_power = get_power(power_A, cnt_A, power_B, cnt_B);
            if (cur_power > best_power) {
                best_power = cur_power;
                best_cnt_A = cnt_A;
                best_cnt_B = cnt_B;
            }

            cnt_B += 1;
        }

        if (cnt_A < 0) {
            break;
        }
    }

    cout << best_cnt_A << ' ' << best_cnt_B;
}