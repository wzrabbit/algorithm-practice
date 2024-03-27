#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Dragon {
    ll d, h;
};

bool operator<(const Dragon& a, const Dragon& b) {
    return a.d < b.d;
}

Dragon dragons[10001];
ll dp[2][10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> dragons[i].d >> dragons[i].h;
    }

    sort(dragons + 1, dragons + N + 1);

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            dp[r % 2][c] = max(dp[(r + 1) % 2][c - 1] + dragons[r].h + dragons[r].d * (c - 1), dp[(r + 1) % 2][c]);
        }
    }

    for (int c = 1; c <= N; c++) {
        cout << dp[N % 2][c] << '\n';
    }
}
