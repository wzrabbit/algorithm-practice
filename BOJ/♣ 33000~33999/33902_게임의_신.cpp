#include <algorithm>
#include <iostream>
using namespace std;

int dp[1001];
int X, Y;

int get_gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }

    return get_gcd(y, x % y);
}

int top_down(int x) {
    if (dp[x] != -1) {
        return dp[x];
    }

    for (int i = x + 1; i <= Y; i++) {
        if (get_gcd(x, i) == 1 && top_down(i) == 0) {
            return dp[x] = 1;
        }
    }

    return dp[x] = 0;
}

int main() {
    cin >> X >> Y;
    fill(dp + 1, dp + Y + 1, -1);

    cout << (top_down(X) == 1 ? "khj20006" : "putdata") << '\n';
}
