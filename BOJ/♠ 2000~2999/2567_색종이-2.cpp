#include <iostream>
using namespace std;

bool board[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int get_round_of_shape() {
    int round_of_shape = 0;

    for (int r = 1; r <= 100; r++) {
        for (int c = 1; c <= 100; c++) {
            for (int i = 0; i < 4; i++) {
                if (board[r][c] == 0) {
                    continue;
                }

                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if (
                    (next_r < 1 || next_r > 100 || next_c < 1 || next_c > 100) ||
                    board[next_r][next_c] == 0) {
                    round_of_shape += 1;
                }
            }
        }
    }

    return round_of_shape;
}

void add_paper(int row, int col) {
    for (int r = row; r < row + 10; r++) {
        for (int c = col; c < col + 10; c++) {
            board[r][c] = true;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int row, col;
        cin >> row >> col;

        add_paper(row, col);
    }

    cout << get_round_of_shape();
}
