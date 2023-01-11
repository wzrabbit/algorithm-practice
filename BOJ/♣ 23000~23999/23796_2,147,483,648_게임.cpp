#include <iostream>
#define EMPTY 0
typedef long long ll;
using namespace std;

ll board[8][8];

void move_board_up() {
    for (int c = 0; c < 8; c++) {
        ll saved_value = EMPTY;
        int index = 0;

        for (int r = 0; r < 8; r++) {
            if (board[r][c] == EMPTY) {
                continue;
            }

            if (saved_value == EMPTY) {
                saved_value = board[r][c];
            } else if (board[r][c] == saved_value) {
                board[index++][c] = saved_value * 2;
                saved_value = EMPTY;
            } else {
                board[index++][c] = saved_value;
                saved_value = board[r][c];
            }

            board[r][c] = EMPTY;
        }

        if (saved_value != EMPTY) {
            board[index++][c] = saved_value;
        }
    }
}

void move_board_down() {
    for (int c = 0; c < 8; c++) {
        ll saved_value = EMPTY;
        int index = 7;

        for (int r = 7; r >= 0; r--) {
            if (board[r][c] == EMPTY) {
                continue;
            }

            if (saved_value == EMPTY) {
                saved_value = board[r][c];
            } else if (board[r][c] == saved_value) {
                board[index--][c] = saved_value * 2;
                saved_value = EMPTY;
            } else {
                board[index--][c] = saved_value;
                saved_value = board[r][c];
            }

            board[r][c] = EMPTY;
        }

        if (saved_value != EMPTY) {
            board[index--][c] = saved_value;
        }
    }
}

void move_board_left() {
    for (int r = 0; r < 8; r++) {
        ll saved_value = EMPTY;
        int index = 0;

        for (int c = 0; c < 8; c++) {
            if (board[r][c] == EMPTY) {
                continue;
            }

            if (saved_value == EMPTY) {
                saved_value = board[r][c];
            } else if (board[r][c] == saved_value) {
                board[r][index++] = saved_value * 2;
                saved_value = EMPTY;
            } else {
                board[r][index++] = saved_value;
                saved_value = board[r][c];
            }

            board[r][c] = EMPTY;
        }

        if (saved_value != EMPTY) {
            board[r][index++] = saved_value;
        }
    }
}

void move_board_right() {
    for (int r = 0; r < 8; r++) {
        ll saved_value = EMPTY;
        int index = 7;

        for (int c = 7; c >= 0; c--) {
            if (board[r][c] == EMPTY) {
                continue;
            }

            if (saved_value == EMPTY) {
                saved_value = board[r][c];
            } else if (board[r][c] == saved_value) {
                board[r][index--] = saved_value * 2;
                saved_value = EMPTY;
            } else {
                board[r][index--] = saved_value;
                saved_value = board[r][c];
            }

            board[r][c] = EMPTY;
        }

        if (saved_value != EMPTY) {
            board[r][index--] = saved_value;
        }
    }
}

int main() {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            cin >> board[r][c];
        }
    }

    char command;
    cin >> command;

    switch (command) {
        case 'U':
            move_board_up();
            break;
        case 'D':
            move_board_down();
            break;
        case 'L':
            move_board_left();
            break;
        case 'R':
            move_board_right();
            break;
    }

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
}