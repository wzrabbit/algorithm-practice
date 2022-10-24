#include <iostream>
using namespace std;

int dp[200001][19];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> dp[i][0];
    }

    for (int j = 1; j <= 18; j++) {
        for (int i = 1; i <= N; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i <= 18; i++) {
            if ((n & (1 << i)) > 0) x = dp[x][i];
        }

        cout << x << '\n';
    }
}