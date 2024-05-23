#include <iostream>
#include <string>
using namespace std;

string cube[7] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."};
char canvas[1002][1002];
int R, C;

void create_cube(int start_r, int start_c) {
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 7; c++) {
            if (cube[r][c] != '.') {
                canvas[r + start_r][c + start_c] = cube[r][c];
            }
        }
    }
}

void print_answer() {
    int start_r = 1000;
    int start_c = 1000;
    int end_r = 1;
    int end_c = 1;

    for (int r = 1; r <= 1000; r++) {
        for (int c = 1; c <= 1000; c++) {
            if (canvas[r][c] != '.') {
                start_r = min(start_r, r);
                start_c = min(start_c, c);
                end_r = max(end_r, r);
                end_c = max(end_c, c);
            }
        }
    }

    for (int r = start_r; r <= end_r; r++) {
        for (int c = start_c; c <= end_c; c++) {
            cout << canvas[r][c];
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    fill(&canvas[1][1], &canvas[1000][1001], '.');

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int height;
            cin >> height;

            for (int i = 1; i <= height; i++) {
                create_cube(500 + r * 2 - i * 3, 500 + c * 4 - r * 2);
            }
        }
    }

    print_answer();
}
