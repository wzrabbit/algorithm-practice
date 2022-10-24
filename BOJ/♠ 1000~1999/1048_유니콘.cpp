#include <algorithm>
#include <iostream>
#include <string>
#define MOD 1000000007
typedef long long ll;
using namespace std;

char grid[302][302];
string word;
ll dp[51][301][301];
ll prefix[301][301];
int R, C, _;

ll get_value(int r, int c) {
    if (r < 0) r = 0;
    if (c < 0) c = 0;
    if (r > R) r = R;
    if (c > C) c = C;
    return prefix[r][c];
}

ll calculate_sum(size_t i, int r, int c) {
    ll res = 0;

    res += get_value(r - 3, c - 2) + get_value(r - 2, c - 3) - get_value(r - 3, c - 3);
    res += get_value(r - 2, C) - get_value(r - 2, c + 1) -
           get_value(r - 2, c + 2) + get_value(r - 3, c + 2) + get_value(r - 2, c + 1) - get_value(r - 3, c + 1);
    res += get_value(R, c - 2) - get_value(r + 1, c - 2) -
           get_value(r + 2, c - 2) + get_value(r + 1, c - 2) + get_value(r + 2, c - 3) - get_value(r + 1, c - 3);
    res += get_value(R, C) - get_value(R, c + 1) - get_value(r + 1, C) + get_value(r + 1, c + 1) -
           get_value(r + 2, c + 2) + get_value(r + 1, c + 2) + get_value(r + 2, c + 1) - get_value(r + 1, c + 1);

    while (res < 0) {
        res += MOD;
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C >> _;
    cin >> word;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == word[0]) {
                dp[1][r][c] = 1;
            }
        }
    }

    for (size_t i = 2; i <= word.size(); i++) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                prefix[r][c] = dp[i - 1][r][c] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
                prefix[r][c] = (prefix[r][c] + MOD) % MOD;
            }
        }

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                if (grid[r][c] == word[i - 1]) {
                    dp[i][r][c] = calculate_sum(i, r, c) % MOD;
                }
            }
        }
    }

    ll res = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            res = (res + dp[word.size()][r][c]) % MOD;
        }
    }

    cout << res;
}