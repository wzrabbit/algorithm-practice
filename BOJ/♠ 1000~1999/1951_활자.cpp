#include <iostream>
#define MOD 1'234'567
typedef long long ll;
using namespace std;

ll get_movable_type_count(ll num) {
    ll level = 1;
    ll need = 9;
    ll cnt = 0;

    while (true) {
        if (num > need) {
            num -= need;
            cnt = (cnt + need * level) % MOD;
            need *= 10;
        } else {
            cnt = (cnt + num * level) % MOD;
            break;
        }

        level += 1;
    }

    return cnt;
}

int main() {
    ll N;
    cin >> N;

    cout << get_movable_type_count(N);
}