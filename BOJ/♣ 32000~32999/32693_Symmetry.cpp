#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

bool dp[501][501][501];
char grid[502][502];
int R, C;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int j = 1; j <= C; j++) {
            for (int i = 1; i <= C; i++) {
                if (i == j) {
                    dp[r][i][j] = true;
                    continue;
                }

                if (grid[r][i] != grid[r][j]) {
                    continue;
                }

                if (dp[r][i + 1][j - 1]) {
                    dp[r][i][j] = true;
                    continue;
                }

                if (abs(i - j) == 1) {
                    dp[r][i][j] = true;
                }
            }
        }
    }

    ll answer = 0;

    for (int s = 1; s <= C; s++) {
        for (int e = s + 1; e <= C; e += 2) {
            ll combo = 0;

            for (int r = 1; r <= R; r++) {
                if (dp[r][s][e]) {
                    combo += 1;
                    answer += combo;
                } else {
                    combo = 0;
                }
            }
        }
    }

    cout << answer;
}
