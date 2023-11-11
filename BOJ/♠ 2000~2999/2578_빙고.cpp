#include <iostream>
using namespace std;

int player[5][5];
int master[25];
bool checked[5][5];

bool is_bingo() {
    int bingo_count = 0;

    for (int r = 0; r < 5; r++) {
        bool success = true;

        for (int c = 0; c < 5; c++) {
            if (!checked[r][c]) {
                success = false;
                break;
            }
        }

        if (success) {
            bingo_count += 1;
        }
    }

    for (int c = 0; c < 5; c++) {
        bool success = true;

        for (int r = 0; r < 5; r++) {
            if (!checked[r][c]) {
                success = false;
                break;
            }
        }

        if (success) {
            bingo_count += 1;
        }
    }

    bool success = true;

    for (int i = 0; i < 5; i++) {
        if (!checked[i][i]) {
            success = false;
            break;
        }
    }

    if (success) {
        bingo_count += 1;
    }

    success = true;

    for (int i = 0; i < 5; i++) {
        if (!checked[i][4 - i]) {
            success = false;
        }
    }

    if (success) {
        bingo_count += 1;
    }

    return bingo_count >= 3;
}

void check(int num) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (player[r][c] == num) {
                checked[r][c] = true;
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            cin >> player[r][c];
        }
    }

    for (int i = 0; i < 25; i++) {
        cin >> master[i];
    }

    for (int i = 0; i < 25; i++) {
        check(master[i]);

        if (is_bingo()) {
            cout << i + 1;
            return 0;
        }
    }
}