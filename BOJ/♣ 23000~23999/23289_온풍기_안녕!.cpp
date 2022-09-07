#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct loc {
    int r, c;
};

struct wind {
    int r, c, t;
};

int R, C, K, W;
int board[21][21];
int wall[21][21];
int state[21][21];
int temp[21][21];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int nr[12] = {-1, -1, -1, -1, 0, 1, 1, 1, 1, 1, 0, -1};
int nc[12] = {-1, 0, 1, 1, 1, 1, 1, 0, -1, -1, -1, -1};
int bit[4] = {1, 2, 4, 8};
int nbit[20] = {8, 4, 1, 2, 4, 1, 8, 2, 4, 8, 2, 1, 4, 8, 1, 4, 2, 8, 1, 2};
int conv[5] = {0, 1, 3, 0, 2};
// ↑: 1  →: 2  ↓: 4  ←: 8

void make_wall(int tr, int tc, int type) {
    if (type == 0) {
        wall[tr][tc] |= 1;
        wall[tr - 1][tc] |= 4;
    } else {
        wall[tr][tc] |= 2;
        wall[tr][tc + 1] |= 8;
    }
}

void activate_heater(int tr, int tc, int type) {
    tr += dr[type];
    tc += dc[type];
    queue<wind> q;
    q.push({tr, tc, 5});
    temp[tr][tc] = 5;

    while (q.size()) {
        wind cur = q.front();
        q.pop();

        if (cur.t == 1)
            continue;

        int up[2] = {cur.r + nr[type * 3], cur.c + nc[type * 3]};
        int mid[2] = {cur.r + nr[type * 3 + 1], cur.c + nc[type * 3 + 1]};
        int down[2] = {cur.r + nr[type * 3 + 2], cur.c + nc[type * 3 + 2]};

        // ↗
        if (up[0] >= 1 && up[0] <= R && up[1] >= 1 && up[1] <= C &&
            temp[up[0]][up[1]] == 0 && !(wall[cur.r][cur.c] & nbit[type * 5]) &&
            !(wall[up[0]][up[1]] & nbit[type * 5 + 1])) {
            temp[up[0]][up[1]] = cur.t - 1;
            q.push({up[0], up[1], cur.t - 1});
        }

        // →
        if (mid[0] >= 1 && mid[0] <= R && mid[1] >= 1 && mid[1] <= C &&
            temp[mid[0]][mid[1]] == 0 && !(wall[cur.r][cur.c] & nbit[type * 5 + 2])) {
            temp[mid[0]][mid[1]] = cur.t - 1;
            q.push({mid[0], mid[1], cur.t - 1});
        }

        // ↘
        if (down[0] >= 1 && down[0] <= R && down[1] >= 1 && down[1] <= C &&
            temp[down[0]][down[1]] == 0 && !(wall[cur.r][cur.c] & nbit[type * 5 + 3]) &&
            !(wall[down[0]][down[1]] & nbit[type * 5 + 4])) {
            temp[down[0]][down[1]] = cur.t - 1;
            q.push({down[0], down[1], cur.t - 1});
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (temp[r][c] > 0) {
                state[r][c] += temp[r][c];
                temp[r][c] = 0;
            }
        }
    }
}

void activate_all_heater() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (board[r][c] >= 1 && board[r][c] <= 4)
                activate_heater(r, c, conv[board[r][c]]);
        }
    }
}

void spread_wind() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            for (int i = 1; i <= 2; i++) {
                int r_ = r + dr[i];
                int c_ = c + dc[i];

                if (r_ >= 1 && r_ <= R && c_ >= 1 && c_ <= C && !(wall[r][c] & bit[i])) {
                    temp[r_][c_] += (state[r][c] - state[r_][c_]) / 4;
                    temp[r][c] += (state[r_][c_] - state[r][c]) / 4;
                }
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            state[r][c] += temp[r][c];
            temp[r][c] = 0;
        }
    }
}

void trim_wind() {
    for (int c = 1; c <= C; c++) {
        if (state[1][c] >= 1)
            state[1][c]--;

        if (state[R][c] >= 1)
            state[R][c]--;
    }

    for (int r = 2; r <= R - 1; r++) {
        if (state[r][1] >= 1)
            state[r][1]--;

        if (state[r][C] >= 1)
            state[r][C]--;
    }
}

bool check() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (board[r][c] == 5 && state[r][c] < K)
                return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++)
            cin >> board[r][c];
    }

    cin >> W;
    for (int i = 0; i < W; i++) {
        int r, c, t;
        cin >> r >> c >> t;
        make_wall(r, c, t);
    }

    int choco = 0;

    while (choco <= 100) {
        activate_all_heater();
        spread_wind();
        trim_wind();
        choco++;

        if (check())
            break;
    }

    cout << choco;
}