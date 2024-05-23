#include <iostream>
using namespace std;

int get_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return get_gcd(b, a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int gcd = N;

    for (int i = 1; i <= M; i++) {
        int cur;
        cin >> cur;

        gcd = get_gcd(gcd, cur);
    }

    cout << ((gcd == 1) ? "Yes" : "No");
}
