#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll grid[33][33];
ll dp[3][33][33];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }
    dp[0][1][2] = 1;
    
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == 1) continue;

            dp[0][r][c] += dp[0][r][c - 1] + dp[1][r][c - 1];
            dp[2][r][c] += dp[2][r - 1][c] + dp[1][r - 1][c];
            
            if (grid[r - 1][c] == 0 && grid[r][c - 1] == 0) {
                for (int i = 0; i < 3; i++) {
                    dp[1][r][c] += dp[i][r - 1][c - 1];
                }
            }
        }
    }
    
    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
}

