#include <iostream>
using namespace std;

bool result[4][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int B, N, R, C;
    cin >> B >> N >> R >> C;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            int cur_row = R - 2 + i;
            int cur_col = C - 2 + j;

            if (cur_row < 1 || cur_row > B || cur_col < 1 || cur_col > B) {
                result[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                int row_gap = R - 2 + i - r;
                int col_gap = C - 2 + j - c;

                if (abs(row_gap) == abs(col_gap) || row_gap == 0 || col_gap == 0) {
                    result[i][j] = true;
                }
            }
        }
    }

    int blocked_count = 0;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (result[i][j]) {
                blocked_count += 1;
            }
        }
    }

    if (blocked_count == 9) {
        cout << "CHECKMATE";
        return 0;
    }

    if (result[2][2]) {
        cout << "CHECK";
        return 0;
    }

    if (blocked_count == 8 && !result[2][2]) {
        cout << "STALEMATE";
        return 0;
    }

    cout << "NONE";
}
