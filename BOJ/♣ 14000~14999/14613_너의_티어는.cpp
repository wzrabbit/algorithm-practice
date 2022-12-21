#include <iomanip>
#include <iostream>
using namespace std;

double dp[21][41];
int range[5][2] = {{0, 9}, {10, 19}, {20, 29}, {30, 39}, {40, 40}};

int main() {
    double win_rate, lose_rate, draw_rate;
    cin >> win_rate >> lose_rate >> draw_rate;
    dp[0][20] = 1;

    for (int r = 0; r < 20; r++) {
        for (int c = 0; c <= 40; c++) {
            if (dp[r][c] > 0) {
                dp[r + 1][c - 1] += dp[r][c] * lose_rate;
                dp[r + 1][c] += dp[r][c] * draw_rate;
                dp[r + 1][c + 1] += dp[r][c] * win_rate;
            }
        }
    }

    cout << fixed << setprecision(8);

    for (int i = 0; i < 5; i++) {
        int start = range[i][0];
        int end = range[i][1];
        double probability = 0;

        for (int c = start; c <= end; c++) {
            probability += dp[20][c];
        }

        cout << probability << '\n';
    }
}