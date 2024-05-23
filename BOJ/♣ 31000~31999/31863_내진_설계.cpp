#include <algorithm>
#include <iostream>
#include <queue>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

struct Boom {
    int r, c, p;
};

char grid[1002][1002];
int hit_count[1002][1002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void simulate(int start_r, int start_c) {
    queue<Boom> q;
    q.push({start_r, start_c, 2});

    while (!q.empty()) {
        Boom cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r;
            int c = cur.c;

            for (int j = 0; j < cur.p; j++) {
                r += dr[i];
                c += dc[i];

                if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == '|') {
                    break;
                }

                hit_count[r][c] += 1;

                if (grid[r][c] == '*' && hit_count[r][c] == 1) {
                    q.push({r, c, 1});
                }

                if (grid[r][c] == '#' && hit_count[r][c] == 2) {
                    q.push({r, c, 1});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '@') {
                simulate(r, c);
            }
        }
    }

    int broken = 0;
    int safe = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '*') {
                if (hit_count[r][c] < 1) {
                    safe += 1;
                } else {
                    broken += 1;
                }
                continue;
            }

            if (grid[r][c] == '#') {
                if (hit_count[r][c] < 2) {
                    safe += 1;
                } else {
                    broken += 1;
                }
            }
        }
    }

    cout << broken << ' ' << safe;
}
