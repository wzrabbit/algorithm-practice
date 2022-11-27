#include <iostream>
#include <algorithm>
using namespace std;

int MOD = 10000;

int dp[101][4][3];
bool is_banned[101][4][3];

int get_day_sum(int day) {
    int sum = 0;
    for (int r = 1; r <= 3; r++) {
        for (int c = 1; c <= 2; c++) {
            sum += dp[day][r][c];
        }
    }
    return sum % MOD;
}

int mod(int value) {
    while (value < 0) value += MOD;
    return value % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    
    for (int i = 1; i <= K; i++) {
        int day, pasta;
        cin >> day >> pasta;
        
        fill(&is_banned[day][1][1], &is_banned[day][3][3], true);
        fill(&is_banned[day][pasta][1], &is_banned[day][pasta][3], false);
    }
    
    if (!is_banned[1][1][1]) dp[1][1][1] = 1;
    if (!is_banned[1][2][1]) dp[1][2][1] = 1;
    if (!is_banned[1][3][1]) dp[1][3][1] = 1;

    for (int day = 2; day <= N; day++) {
        for (int taste = 1; taste <= 3; taste++) {
            if (!is_banned[day][taste][1]) {
                dp[day][taste][1] = get_day_sum(day - 1) - dp[day - 1][taste][1] - dp[day - 1][taste][2];
                dp[day][taste][1] = mod(dp[day][taste][1]);
            }
            
            if (!is_banned[day][taste][2]) {
                dp[day][taste][2] = dp[day - 1][taste][1];
                dp[day][taste][2] = mod(dp[day][taste][2]);
            }
        }
    }
    
    cout << get_day_sum(N);
}
