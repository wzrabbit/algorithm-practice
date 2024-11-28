#include <iostream>
using namespace std;

struct Pos {
    int r, c;
};

int dust[51][51];
int next_dust[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int air_conditioner_row;
int R, C, T;

Pos get_next_circulation_pos(Pos cur) {
    if (
        (cur.c == 1 && cur.r < air_conditioner_row - 1) ||
        (cur.c == C && cur.r >= air_conditioner_row && cur.r != R)) {
        return {cur.r + 1, cur.c};
    }

    if (
        (cur.r == 1 && cur.c != 1) ||
        (cur.r == R && cur.c != 1)) {
        return {cur.r, cur.c - 1};
    }

    if (
        (cur.r == air_conditioner_row - 1 && cur.c != C) ||
        (cur.r == air_conditioner_row && cur.c != C)) {
        return {cur.r, cur.c + 1};
    }

    return {cur.r - 1, cur.c};
}

void spread_dust() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int spread_count = 0;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (
                    nr < 1 ||
                    nr > R ||
                    nc < 1 ||
                    nc > C ||
                    (nr == air_conditioner_row && nc == 1) ||
                    (nr == air_conditioner_row - 1 && nc == 1)) {
                    continue;
                }

                next_dust[nr][nc] += dust[r][c] / 5;
                spread_count += 1;
            }

            next_dust[r][c] += dust[r][c] - dust[r][c] / 5 * spread_count;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            dust[r][c] = next_dust[r][c];
            next_dust[r][c] = 0;
        }
    }
}

void circulate_dust() {
    int r = air_conditioner_row - 1;
    int c = 1;
    int repeat_count = C * 2 + (air_conditioner_row - 1) * 2 - 4;

    for (int i = 1; i <= repeat_count; i++) {
        Pos next_pos = get_next_circulation_pos({r, c});
        next_dust[next_pos.r][next_pos.c] = dust[r][c];
        r = next_pos.r;
        c = next_pos.c;
    }

    r = air_conditioner_row;
    c = 1;
    repeat_count = C * 2 + (R - air_conditioner_row) * 2 - 2;

    for (int i = 1; i <= repeat_count; i++) {
        Pos next_pos = get_next_circulation_pos({r, c});
        next_dust[next_pos.r][next_pos.c] = dust[r][c];
        r = next_pos.r;
        c = next_pos.c;
    }

    next_dust[air_conditioner_row - 1][1] = 0;
    next_dust[air_conditioner_row][1] = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (
                r == 1 ||
                c == 1 ||
                r == R ||
                c == C ||
                r == air_conditioner_row - 1 ||
                r == air_conditioner_row) {
                dust[r][c] = next_dust[r][c];
                next_dust[r][c] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> T;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> dust[r][c];

            if (dust[r][c] == -1) {
                dust[r][c] = 0;
                air_conditioner_row = r;
            }
        }
    }

    while (T--) {
        spread_dust();
        circulate_dust();
    }

    int total_dust = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            total_dust += dust[r][c];
        }
    }

    cout << total_dust;
}
