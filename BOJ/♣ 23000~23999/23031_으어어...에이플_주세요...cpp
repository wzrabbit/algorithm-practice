#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// row, col, direction, alive
struct Ari {
    int r, c, d;
    bool a;
};

char grid[17][17];
bool zombie[2][17][17];
bool light[16][16];
int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};
Ari ari;
int N;

void activate_light(int cur_r, int cur_c) {
    light[cur_r][cur_c] = true;

    for (int i = 0; i < 8; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];

        if (r >= 1 && r <= N && c >= 1 && c <= N) {
            light[r][c] = true;
        }
    }
}

bool met_zombie(int cur_r, int cur_c) {
    if (light[cur_r][cur_c]) {
        return false;
    }

    if (zombie[0][cur_r][cur_c] || zombie[1][cur_r][cur_c]) {
        return true;
    }

    return false;
}

void zombie_move() {
    for (int r = N + 1; r >= 1; r--) {
        for (int c = 1; c <= N; c++) {
            zombie[0][r][c] = zombie[0][r - 1][c];
        }
    }

    for (int r = 0; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            zombie[1][r][c] = zombie[1][r + 1][c];
        }
    }

    for (int c = 1; c <= N; c++) {
        if (zombie[0][N + 1][c]) {
            zombie[0][N + 1][c] = false;
            zombie[1][N][c] = true;
        }

        if (zombie[1][0][c]) {
            zombie[1][0][c] = false;
            zombie[0][1][c] = true;
        }
    }
}

void move(char command) {
    if (command == 'F') {
        int r = ari.r + dr[ari.d];
        int c = ari.c + dc[ari.d];

        if (r >= 1 && r <= N && c >= 1 && c <= N) {
            ari.r = r;
            ari.c = c;

            if (grid[r][c] == 'S') {
                activate_light(r, c);
            }
        }
    } else if (command == 'L') {
        ari.d = (ari.d + 3) % 4;
    } else {
        ari.d = (ari.d + 1) % 4;
    }

    if (met_zombie(ari.r, ari.c)) {
        ari.a = false;
    }

    zombie_move();

    if (met_zombie(ari.r, ari.c)) {
        ari.a = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    string commands;
    cin >> commands;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == 'Z') {
                zombie[0][r][c] = true;
            }
        }
    }

    ari.r = 1;
    ari.c = 1;
    ari.d = 2;
    ari.a = true;

    for (size_t i = 0; i < commands.size(); i++) {
        move(commands[i]);

        if (!ari.a) {
            cout << "Aaaaaah!";
            return 0;
        }
    }

    cout << "Phew...";
}