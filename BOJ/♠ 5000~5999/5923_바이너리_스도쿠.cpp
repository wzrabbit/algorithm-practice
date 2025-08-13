#include <algorithm>
#include <iostream>
#define INF 1'000'000'000
using namespace std;

char grid[12][12];
int dp[10][8][512];

int get_bit_count(int number) {
    int bit_count = 0;

    for (int i = 0; i < 9; i++) {
        if (number & (1 << i)) {
            bit_count += 1;
        }
    }

    return bit_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 9; i++) {
        cin >> (grid[i] + 1);
    }

    fill(&dp[0][0][0], &dp[9][7][511] + 1, INF);
    dp[0][0][0] = 0;

    for (int i = 0; i <= 8; i++) {
        int square_bit = 0;
        int vertical_bit = 0;

        for (int j = 1; j <= 9; j++) {
            if (grid[i + 1][j] == '1') {
                square_bit ^= (1 << ((9 - j) / 3));
                vertical_bit |= (1 << (9 - j));
            }
        }

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 512; k++) {
                if (dp[i][j][k] == INF) {
                    continue;
                }

                for (int l = 0; l < 512; l++) {
                    int next_square_bit = square_bit ^ j;
                    int next_vertical_bit = vertical_bit ^ k ^ l;

                    for (int m = 0; m < 9; m++) {
                        if (l & (1 << m)) {
                            next_square_bit ^= 1 << (m / 3);
                        }
                    }

                    if (get_bit_count(next_vertical_bit) % 2 == 1) {
                        continue;
                    }

                    if (i % 3 == 2 && next_square_bit != 0) {
                        continue;
                    }

                    int cost = get_bit_count(l);
                    dp[i + 1][next_square_bit][next_vertical_bit] =
                        min(dp[i + 1][next_square_bit][next_vertical_bit],
                            dp[i][j][k] + cost);
                }
            }
        }
    }

    cout << dp[9][0][0];
}
