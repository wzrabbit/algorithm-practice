#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    ll result = 1;

    for (ll i = 1; i <= N; i++) {
        result = result * i % M;

        if (result == 0) {
            break;
        }
    }

    cout << result;
}
