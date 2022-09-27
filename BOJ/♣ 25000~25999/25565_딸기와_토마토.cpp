#include <algorithm>
#include <iostream>
using namespace std;

int grid[2001][2001];
int prefix[2001][2001];
int ans[2001][2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, L;
    cin >> R >> C >> L;
    int cnt1 = 0;
    int cnt2 = 0;
    int found = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
            prefix[r][c] = grid[r][c] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    for (int r = 1; r <= R - L + 1; r++) {
        for (int c = 1; c <= C; c++) {
            if (prefix[r + L - 1][c] - prefix[r + L - 1][c - 1] - prefix[r - 1][c] + prefix[r - 1][c - 1] == L) {
                found++;
                for (int i = r; i <= r + L - 1; i++) {
                    ans[i][c]++;
                    if (ans[i][c] == 2)
                        cnt2++;
                    else
                        cnt1++;
                }
            }
        }
    }

    if (L > 1 && found < 2) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C - L + 1; c++) {
                if (prefix[r][c + L - 1] - prefix[r][c - 1] - prefix[r - 1][c + L - 1] + prefix[r - 1][c - 1] == L) {
                    found++;
                    for (int i = c; i <= c + L - 1; i++) {
                        ans[r][i]++;
                        if (ans[r][i] == 2)
                            cnt2++;
                        else
                            cnt1++;
                    }
                }
            }
        }
    }

    if (found == 1)
        cout << cnt1 << '\n';
    else
        cout << cnt2 << '\n';

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (ans[r][c] == 2 || (found == 1 && ans[r][c] == 1))
                cout << r << ' ' << c << '\n';
        }
    }
}