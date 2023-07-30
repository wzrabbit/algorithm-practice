#include <algorithm>
#include <iostream>
#define INF 123'456'789
using namespace std;

int grape[51][51];
int prefix[51][51];
int dp[51][51][51][51];
int R, C;

void init() {
    for (int sr = 1; sr <= R; sr++) {
        for (int er = sr; er <= R; er++) {
            for (int sc = 1; sc <= C; sc++) {
                for (int ec = sc; ec <= C; ec++) {
                    if (sr == er && sc == ec) {
                        dp[sr][sc][er][ec] = 0;
                    } else {
                        dp[sr][sc][er][ec] = INF;
                    }
                }
            }
        }
    }
}

int get_prefix(int sr, int sc, int er, int ec) {
    return prefix[er][ec] - prefix[sr - 1][ec] - prefix[er][sc - 1] + prefix[sr - 1][sc - 1];
}

int top_down(int sr, int sc, int er, int ec) {
    int &cur = dp[sr][sc][er][ec];

    if (cur != INF) {
        return cur;
    }

    for (int r = sr; r <= er - 1; r++) {
        cur = min(cur, top_down(sr, sc, r, ec) + top_down(r + 1, sc, er, ec) + get_prefix(sr, sc, er, ec));
    }

    for (int c = sc; c <= ec - 1; c++) {
        cur = min(cur, top_down(sr, sc, er, c) + top_down(sr, c + 1, er, ec) + get_prefix(sr, sc, er, ec));
    }

    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grape[r][c];
            prefix[r][c] = grape[r][c] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    init();
    cout << top_down(1, 1, R, C);
}