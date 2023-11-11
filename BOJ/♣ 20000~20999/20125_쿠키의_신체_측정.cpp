#include <iostream>
using namespace std;

char grid[1003][1003];
int answer[8];
int N;

void calculate_left_arm_size(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    int size = 1;

    while (c - 1 >= 1 && grid[r][c - 1] == '*') {
        size += 1;
        c -= 1;
    }

    answer[3] = size;
}

void calculate_right_arm_size(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    int size = 1;

    while (c + 1 <= N && grid[r][c + 1] == '*') {
        size += 1;
        c += 1;
    }

    answer[4] = size;
}

void calculate_left_leg_size(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    int size = 1;

    while (r + 1 <= N && grid[r + 1][c] == '*') {
        size += 1;
        r += 1;
    }

    answer[6] = size;
}

void calculate_right_leg_size(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    int size = 1;

    while (r + 1 <= N && grid[r + 1][c] == '*') {
        size += 1;
        r += 1;
    }

    answer[7] = size;
}

void calculate_waist_size(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    int size = 1;

    while (grid[r + 1][c] == '*') {
        size += 1;
        r += 1;
    }

    answer[5] = size;

    calculate_left_leg_size(r + 1, c - 1);
    calculate_right_leg_size(r + 1, c + 1);
}

void find_heart() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (grid[r][c] == '*') {
                answer[1] = r + 1;
                answer[2] = c;

                calculate_left_arm_size(r + 1, c - 1);
                calculate_right_arm_size(r + 1, c + 1);
                calculate_waist_size(r + 2, c);

                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    find_heart();

    cout << answer[1] << ' ' << answer[2] << '\n';

    for (int i = 3; i <= 7; i++) {
        cout << answer[i] << ' ';
    }
}