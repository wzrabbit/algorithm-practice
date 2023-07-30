#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ll N;
    cin >> N;

    ll result = 1;

    for (ll i = 2; i <= N; i++) {
        result *= i;
    }

    cout << result / 604800;
}