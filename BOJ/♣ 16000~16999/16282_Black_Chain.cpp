#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;

    for (int i = 1; i <= 54; i++) {
        ll result = i;
        ll cur = i + 1;

        for (int j = 1; j <= i + 1; j++) {
            result += cur;
            cur *= 2;
        }

        if (result >= N) {
            cout << i;
            return 0;
        }
    }
}
