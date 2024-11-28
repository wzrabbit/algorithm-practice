#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

void invert_board_case(vector<string>& board) {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] >= 'a' && board[r][c] <= 'z') {
                board[r][c] = board[r][c] - 'a' + 'A';
                continue;
            }

            if (board[r][c] >= 'A' && board[r][c] <= 'Z') {
                board[r][c] = board[r][c] - 'A' + 'a';
                continue;
            }
        }
    }
}

string get_state(char mover, char target) {
    if (target == '.') {
        return "empty";
    }

    if (
        (mover >= 'a' && mover <= 'z' && target >= 'a' && target <= 'z') ||
        (mover >= 'A' && mover <= 'Z' && target >= 'A' && target <= 'Z')) {
        return "ally";
    }

    return "enemy";
}

bool is_piece_movable(Pos start, Pos end, vector<string>& board) {
    int r_diff = end.r - start.r;
    int c_diff = end.c - start.c;
    char piece = board[start.r][start.c];

    if ((piece == 'K' || piece == 'k') && (abs(r_diff) > 1 || abs(c_diff) > 1)) {
        return false;
    }

    if ((piece == 'Q' || piece == 'q') && r_diff != 0 && c_diff != 0 && abs(r_diff) != abs(c_diff)) {
        return false;
    }

    if ((piece == 'R' || piece == 'r') && r_diff != 0 && c_diff != 0) {
        return false;
    }

    if ((piece == 'B' || piece == 'b') && abs(r_diff) != abs(c_diff)) {
        return false;
    }

    if (piece == 'N' || piece == 'n') {
        if (!(
                (abs(r_diff) == 2 && abs(c_diff) == 1) ||
                (abs(r_diff) == 1 && abs(c_diff) == 2))) {
            return false;
        }

        return get_state(piece, board[end.r][end.c]) != "ally";
    }

    int dr = 0, dc = 0;

    if (r_diff != 0) {
        dr = r_diff > 0 ? 1 : -1;
    }

    if (c_diff != 0) {
        dc = c_diff > 0 ? 1 : -1;
    }

    for (int i = 1; i <= 8; i++) {
        int r = start.r + dr * i;
        int c = start.c + dc * i;

        string state = get_state(board[start.r][start.c], board[r][c]);

        if (state == "ally") {
            return false;
        }

        if (r == end.r && c == end.c) {
            break;
        }

        if (state == "enemy") {
            return false;
        }
    }

    return true;
}

Pos get_king_position(vector<string>& board) {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] == 'k') {
                return {r, c};
            }
        }
    }

    return {0, 0};
}

bool is_under_attack(vector<string>& board) {
    Pos king_pos = get_king_position(board);

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            if (board[r][c] < 'A' || board[r][c] > 'Z') {
                continue;
            }

            if (is_piece_movable({r, c}, king_pos, board)) {
                return true;
            }
        }
    }

    return false;
}

bool simulate_piece_moving(Pos mover, Pos target, vector<string>& board) {
    char cur_piece = board[mover.r][mover.c];
    char prev_piece = board[target.r][target.c];

    board[mover.r][mover.c] = '.';
    board[target.r][target.c] = cur_piece;

    bool result = is_under_attack(board);

    board[mover.r][mover.c] = cur_piece;
    board[target.r][target.c] = prev_piece;

    return result;
}

bool is_checkmate(vector<string>& board) {
    for (int r1 = 0; r1 < 8; r1++) {
        for (int c1 = 0; c1 < 8; c1++) {
            for (int r2 = 0; r2 < 8; r2++) {
                for (int c2 = 0; c2 < 8; c2++) {
                    if (board[r1][c1] < 'a' || board[r1][c1] > 'z') {
                        continue;
                    }

                    if (!is_piece_movable({r1, c1}, {r2, c2}, board)) {
                        continue;
                    }

                    if (!simulate_piece_moving({r1, c1}, {r2, c2}, board)) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        char team;
        cin >> team;

        vector<string> board(8);

        for (int r = 0; r < 8; r++) {
            cin >> board[r];
        }

        if (team == 'B') {
            invert_board_case(board);
        }

        string team_name = team == 'w' ? "WHITE" : "BLACK";

        bool is_first_board_check = is_under_attack(board);

        if (is_checkmate(board)) {
            cout << team_name << " IS CHECKMATED\n";
            continue;
        }

        if (is_first_board_check) {
            cout << team_name << " IS CHECKED\n";
            continue;
        }

        cout << team_name << " IS SAFE\n";
    }
}
