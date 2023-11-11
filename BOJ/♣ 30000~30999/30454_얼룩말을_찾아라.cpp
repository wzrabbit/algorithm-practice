#include <iostream>
using namespace std;

char grid[1005][1005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int best_count = 0;
    int best_stripe = 0;

    for (int r = 1; r <= R; r++) {
        int cur_stripe = 0;

        for (int c = 1; c <= C; c++) {
            if ((c == 1 && grid[r][c] == '1') || (grid[r][c - 1] == '0' && grid[r][c] == '1')) {
                cur_stripe += 1;
            }
        }

        if (cur_stripe > best_stripe) {
            best_count = 1;
            best_stripe = cur_stripe;
        } else if (cur_stripe == best_stripe) {
            best_count += 1;
        }
    }

    cout << best_stripe << ' ' << best_count;
}
