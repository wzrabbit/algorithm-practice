#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

char grid[502][502];
int cnt[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, K;
    cin >> R >> C >> K;

    int changed = 0;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= K; r++) {
        for (int c = 1; c <= K; c++) {
            fill(cnt, cnt + 26, 0);

            for (int i = r; i <= R; i += K) {
                for (int j = c; j <= C; j += K) {
                    cnt[grid[i][j] - 'A'] += 1;
                }
            }

            int best = 0;
            int best_cnt = 0;

            for (int i = 0; i < 26; i++) {
                if (cnt[i] > best_cnt) {
                    best = i;
                    best_cnt = cnt[i];
                }
            }

            char decide = 'A' + best;

            for (int i = r; i <= R; i += K) {
                for (int j = c; j <= C; j += K) {
                    if (grid[i][j] == decide) continue;

                    grid[i][j] = decide;
                    changed += 1;
                }
            }
        }
    }

    cout << changed << '\n';

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c];
        }
        cout << '\n';
    }
}