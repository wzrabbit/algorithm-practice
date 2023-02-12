#include <iostream>
#include <algorithm>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[101][101];

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int cnt, len;
        cin >> cnt >> len;
        
        fill(&dp[0][0], &dp[len][cnt + 1], 0);
        dp[0][0] = 1;
        
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= cnt; j++) {
                dp[i][j] = (dp[i - 1][j - 1] * (cnt - j + 1) + dp[i - 1][j] * j) % MOD;
            }
        }
        
        cout << "Case #" << t << ": " << dp[len][cnt] << '\n';
    }
}