#include <iostream>
using namespace std;

int happiness[1001][1001];
bool visited[1001][1001];
int c_dr[4] = {-1, 0, 0, 1};
int c_dc[4] = {0, -1, 1, 0};
char c_dir[4] = {'U', 'L', 'R', 'D'};
int d_dr[4] = {-1, 1, 0, 0};
int d_dc[4] = {0, 0, -1, 1};
char d_dir[4] = {'U', 'D', 'L', 'R'};

int R, C;
int cur_r = 1;
int cur_c = 1;

void ban_worst_cell() {
    int ban_r = -1;
    int ban_c = -1;
    int minimum_score = 1000;

    for (int r = 1; r <= R; r++) {
        for (int c = r % 2 + 1; c <= C; c += 2) {
            if (happiness[r][c] < minimum_score) {
                ban_r = r;
                ban_c = c;
                minimum_score = happiness[r][c];
            }
        }
    }

    visited[ban_r][ban_c] = true;
}

void perform_path_A() {
    for (int r = 1; r <= R; r++) {
        if (r % 2 == 1) {
            for (int c = 1; c <= C - 1; c++) {
                cout << "R";
            }
        } else {
            for (int c = 1; c <= C - 1; c++) {
                cout << "L";
            }
        }

        if (r != R) {
            cout << "D";
        }
    }
}

void perform_path_B() {
    for (int c = 1; c <= C; c++) {
        if (c % 2 == 1) {
            for (int r = 1; r <= R - 1; r++) {
                cout << "D";
            }
        } else {
            for (int r = 1; r <= R - 1; r++) {
                cout << "U";
            }
        }

        if (c != C) {
            cout << "R";
        }
    }
}

void perform_path_C() {
    int LEFT = 1;
    int RIGHT = 2;
    int direction = RIGHT;

    while (!(cur_r == R - 1 && cur_c == 1)) {
        visited[cur_r][cur_c] = true;

        for (int i = 0; i < 4; i++) {
            int r = cur_r + c_dr[i];
            int c = cur_c + c_dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            if (i == LEFT && direction == RIGHT || i == RIGHT && direction == LEFT) {
                continue;
            }

            if (c == 1) {
                direction = RIGHT;
            }

            if (c == C) {
                direction = LEFT;
            }

            cur_r = r;
            cur_c = c;

            cout << c_dir[i];
            break;
        }
    }
}

void perform_path_D() {
    int LEFT = 2;
    int RIGHT = 3;
    int direction = RIGHT;

    while (!(cur_r == R && cur_c == C)) {
        visited[cur_r][cur_c] = true;

        for (int i = 0; i < 4; i++) {
            int r = cur_r + d_dr[i];
            int c = cur_c + d_dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            if (i == LEFT && direction == RIGHT || i == RIGHT && direction == LEFT) {
                continue;
            }

            if (c == 1) {
                direction = RIGHT;
            }

            if (c == C) {
                direction = LEFT;
            }

            cur_r = r;
            cur_c = c;

            cout << d_dir[i];
            break;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> happiness[r][c];
        }
    }

    if (R % 2 == 1) {
        perform_path_A();
        return 0;
    }

    if (C % 2 == 1) {
        perform_path_B();
        return 0;
    }

    ban_worst_cell();
    perform_path_C();
    perform_path_D();
}