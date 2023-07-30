#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll arr[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll sum = 0;
    ll total = 0;

    for (int i = N; i >= 2; i--) {
        sum += arr[i];
        total = (total + sum * arr[i - 1]) % MOD;
    }

    cout << total;
}