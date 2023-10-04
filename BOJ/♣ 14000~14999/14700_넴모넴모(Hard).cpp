#include <algorithm>
#include <iostream>
#define MOD 1'000'000'007
using namespace std;

int dp[300][262144];
int R, C;

int top_down(int pos, int bit) {
    if (pos == R * C) {
        return 1;
    }

    if (dp[pos][bit] != -1) {
        return dp[pos][bit];
    }

    int not_used_nemmo = top_down(pos + 1, bit >> 1);

    int used_nemmo = ((bit & 1) == 0 || (bit & 2) == 0 || (bit & (1 << C)) == 0 || pos % C == 0)
                         ? top_down(pos + 1, (bit | (1 << (C + 1))) >> 1)
                         : 0;

    return dp[pos][bit] = (not_used_nemmo + used_nemmo) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    if (R < C) {
        swap(R, C);
    }

    fill(&dp[0][0], &dp[R * C - 1][262144], -1);

    cout << top_down(0, 0);
}
