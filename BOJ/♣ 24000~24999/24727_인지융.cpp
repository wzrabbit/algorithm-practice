#include <iostream>
using namespace std;

int grid[111][111];
int dr[5] = {-1, 1, 0, 0, 0};
int dc[5] = {0, 0, -1, 1, 0};
bool success = true;
int N, A, B;

void fill_A() {
    for (int l = 1; l <= N * 2; l++) {
        for (int r = 1; r <= l; r++) {
            if (A <= 0) return;

            int c = l - r + 1;

            if (r >= 1 && r <= N && c >= 1 && c <= N && grid[r][c] == 0) {
                grid[r][c] = 1;
                A -= 1;
            }
        }
    }
}

bool is_occupied(int cur_r, int cur_c) {
    for (int i = 0; i < 5; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];

        if (r >= 1 && r <= N && c >= 1 && c <= N && grid[r][c] == 1) {
            return true;
        }
    }

    return false;
}

void fill_B() {
    for (int l = 1; l <= N * 2; l++) {
        for (int r = N; r >= N - l + 1; r--) {
            if (B <= 0) return;

            int c = N * 2 - l + 1 - r;

            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (is_occupied(r, c)) {
                    success = false;
                    return;
                }

                grid[r][c] = 2;
                B -= 1;
            }
        }
    }
}

int main() {
    cin >> N >> A >> B;

    fill_A();
    fill_B();

    if (!success) {
        cout << -1;
        return 0;
    }

    cout << 1 << '\n';

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << grid[r][c];
        }
        cout << '\n';
    }
}