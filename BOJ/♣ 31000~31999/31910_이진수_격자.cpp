#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll grid[31][31];
ll dp[31][31];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]) * 2 + grid[r][c];
        }
    }

    cout << dp[N][N];
}
