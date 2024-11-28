#include <iostream>
#include <queue>
#define SIMULATION_COUNT 5'000'000
using namespace std;

struct Loc {
    int r, c;
};

int arrow[501][501];
bool has_apple[501][501];
bool is_occupied[501][501];
int R, C, head_r, head_c, tail_r, tail_c;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int simulate() {
    queue<Loc> snake;
    snake.push({tail_r, tail_c});
    snake.push({head_r, head_c});
    is_occupied[tail_r][tail_c] = true;
    is_occupied[head_r][head_c] = true;
    int score = 2;
    int r_gap = head_r - tail_r;
    int c_gap = head_c - tail_c;
    int direction;

    if (r_gap != 0) {
        if (r_gap == -1) {
            direction = 0;
        } else {
            direction = 2;
        }
    }

    if (c_gap != 0) {
        if (c_gap == -1) {
            direction = 3;
        } else {
            direction = 1;
        }
    }

    for (int i = 1; i <= SIMULATION_COUNT; i++) {
        Loc cur = snake.back();
        int next_direction = arrow[cur.r][cur.c];

        if (abs(direction - next_direction) == 2) {
            next_direction = direction;
        }

        int r = cur.r + dr[next_direction];
        int c = cur.c + dc[next_direction];

        if (r < 1 || r > R || c < 1 || c > C) {
            break;
        }

        if (has_apple[r][c]) {
            has_apple[r][c] = false;
        } else {
            Loc tail = snake.front();
            is_occupied[tail.r][tail.c] = false;
            snake.pop();
        }

        if (is_occupied[r][c]) {
            break;
        }

        snake.push({r, c});
        is_occupied[r][c] = true;

        score = snake.size();
        direction = next_direction;
    }

    return score;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> head_r >> head_c >> tail_r >> tail_c;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> arrow[r][c];
        }
    }

    int A;
    cin >> A;

    for (int i = 1; i <= A; i++) {
        int r, c;
        cin >> r >> c;

        has_apple[r][c] = true;
    }

    cout << simulate();
}
