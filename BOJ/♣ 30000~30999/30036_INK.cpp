#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Square {
    int r, c, ink;
};

string ink_string, commands;
Square cur;
int ink_index = 0;
char grid[102][102];
int I, N, K;

void init_square() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '@') {
                cur.r = r;
                cur.c = c;
                cur.ink = 0;
                grid[r][c] = '.';

                return;
            }
        }
    }
}

void move(char command) {
    switch (command) {
        case 'U':
            if (cur.r > 1 && grid[cur.r - 1][cur.c] == '.') {
                cur.r -= 1;
            }
            break;
        case 'D':
            if (cur.r < N && grid[cur.r + 1][cur.c] == '.') {
                cur.r += 1;
            }
            break;
        case 'L':
            if (cur.c > 1 && grid[cur.r][cur.c - 1] == '.') {
                cur.c -= 1;
            }
            break;
        case 'R':
            if (cur.c < N && grid[cur.r][cur.c + 1] == '.') {
                cur.c += 1;
            }
            break;
    }
}

void charge() {
    cur.ink += 1;
}

void jump() {
    for (int r = cur.r - cur.ink; r <= cur.r + cur.ink; r++) {
        for (int c = cur.c - cur.ink; c <= cur.c + cur.ink; c++) {
            if (
                r >= 1 &&
                r <= N &&
                c >= 1 &&
                c <= N &&
                grid[r][c] != '.' &&
                abs(cur.r - r) + abs(cur.c - c) <= cur.ink) {
                grid[r][c] = ink_string[ink_index];
            }
        }
    }

    cur.ink = 0;
    ink_index = (ink_index + 1) % ink_string.size();
}

void perform_command(char command) {
    switch (command) {
        case 'U':
        case 'D':
        case 'L':
        case 'R':
            move(command);
            break;
        case 'J':
            jump();
            break;
        case 'j':
            charge();
            break;
    }
}

void print_result() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (r == cur.r && c == cur.c) {
                cout << '@';
                continue;
            }

            cout << grid[r][c];
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> I >> N >> K >> ink_string;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    cin >> commands;

    init_square();

    for (size_t i = 0; i < commands.size(); i++) {
        perform_command(commands[i]);
    }

    print_result();
}