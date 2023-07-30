#include <algorithm>
#include <iostream>
#define MOD 1'000'000'000
typedef long long ll;
using namespace std;

ll dp[1000001];

ll top_down(ll num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    if (dp[num] != 0) return dp[num];

    return dp[num] = (top_down(num - 1) + top_down(num - 2)) % MOD;
}

int main() {
    ll N;
    cin >> N;

    if (N == 0) {
        cout << "0\n";
    } else if (N > 0 || abs(N) % 2 == 1) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }

    cout << top_down(abs(N));
}