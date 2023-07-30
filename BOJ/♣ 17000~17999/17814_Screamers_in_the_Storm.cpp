#include <algorithm>
#include <iostream>
using namespace std;

int wolf[21][21];
int sheep[21][21];
int biome[21][21];
int T, R, C;

void init() {
    cin >> T >> R >> C;

    fill(&biome[1][1], &biome[R][C + 1], 0);
    fill(&wolf[1][1], &wolf[R][C + 1], -2);
    fill(&sheep[1][1], &sheep[R][C + 1], -2);
}

void place_animals() {
    char input[21][22];

    for (int r = 1; r <= R; r++) {
        cin >> (input[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (input[r][c] == 'S') {
                sheep[r][c] = 5;
            } else if (input[r][c] == 'W') {
                wolf[r][c] = 10;
            }
        }
    }
}

void move_wolves() {
    for (int r = 1; r <= R; r++) {
        int temp = wolf[r][C];

        for (int c = C; c >= 2; c--) {
            wolf[r][c] = wolf[r][c - 1];

            if (wolf[r][c] > 0) {
                wolf[r][c] -= 1;
            }
        }

        wolf[r][1] = temp;
        if (wolf[r][1] > 0) {
            wolf[r][1] -= 1;
        }
    }
}

void move_sheep() {
    for (int c = 1; c <= C; c++) {
        int temp = sheep[R][c];

        for (int r = R; r >= 2; r--) {
            sheep[r][c] = sheep[r - 1][c];

            if (sheep[r][c] > 0) {
                sheep[r][c] -= 1;
            }
        }

        sheep[1][c] = temp;
        if (sheep[1][c] > 0) {
            sheep[1][c] -= 1;
        }
    }
}

void wolves_eat_sheep() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (wolf[r][c] >= 0 && sheep[r][c] >= 0) {
                wolf[r][c] = 10;
                sheep[r][c] = -2;
                biome[r][c] = -2;
            }
        }
    }
}

void sheep_eat_grass() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (biome[r][c] == 3 && sheep[r][c] >= 0) {
                biome[r][c] = -1;
                sheep[r][c] = 5;
            }
        }
    }
}

void starve_kill_animals() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (wolf[r][c] == 0) {
                wolf[r][c] = -2;
                biome[r][c] = -2;
            }

            if (sheep[r][c] == 0) {
                sheep[r][c] = -2;
                biome[r][c] = -2;
            }
        }
    }
}

void grow_grass() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (biome[r][c] >= -1 && biome[r][c] < 3) {
                biome[r][c] += 1;
            }
        }
    }
}

void perform_round() {
    move_wolves();
    move_sheep();
    wolves_eat_sheep();
    sheep_eat_grass();
    starve_kill_animals();
    grow_grass();
}

void print_result() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (wolf[r][c] >= 1) {
                cout << "W";
            } else if (sheep[r][c] >= 1) {
                cout << "S";
            } else if (biome[r][c] == 3) {
                cout << "#";
            } else if (biome[r][c] == -2) {
                cout << "*";
            } else {
                cout << ".";
            }
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();
    place_animals();

    while (T--) {
        perform_round();
    }

    print_result();
}